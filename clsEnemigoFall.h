#ifndef CLSENEMIGOFALL_H_INCLUDED
#define CLSENEMIGOFALL_H_INCLUDED

using namespace std;



class Fall : public sf::Drawable {
private:

    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float _verticalSpeed;
    bool _onGround;
    bool _isDead;
    bool _isDetected;
    bool _vacio;
    float radioDeteccion;

    void setOriginToCenter();

    sf::Clock _detectionClock;



public:
    Fall(){}
    Fall(const string& textureFile, sf::Vector2f v, float dr) {
        _texture.loadFromFile(textureFile);
        _sprite.setTexture(_texture);
        setOriginToCenter();
        _velocity = v;
        _verticalSpeed = 0;
        _isDead = false;
        _onGround = false;
        _vacio=false;
        radioDeteccion = dr;
    }
    sf::FloatRect getLimite(){return _sprite.getGlobalBounds();}

        float getSuperior(){
     return _sprite.getPosition().y;
    }


    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }
    bool isPlatformBelow(const vector<sf::FloatRect>& platforms);
    void update(const vector<sf::FloatRect>& platforms, const sf::Vector2f& heroPosition);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void resolveCollisions(const vector<sf::FloatRect>& platforms);
};

bool Fall::isPlatformBelow(const vector<sf::FloatRect>& platforms) {
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    sf::FloatRect below(bounds.left, bounds.top + bounds.height + 1, bounds.width, 1); // Un rectángulo justo debajo del enemigo

    for (const auto& platform : platforms) {
        if (below.intersects(platform)) {
            return true;
        }
    }
    return false;
}



void Fall::setOriginToCenter() {
    sf::FloatRect bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}


void Fall::update(const vector<sf::FloatRect>& platforms, const sf::Vector2f& heroPosition) {
    if (!_onGround) {
        _verticalSpeed += GRAVITY;
    } else {
        _verticalSpeed = 0;
    }

    float distancia = distance(_sprite.getPosition(), heroPosition);
    if (distancia <= radioDeteccion) {
        if (!_isDetected) {
            _detectionClock.restart();
            _isDetected = true;
        } else if (_detectionClock.getElapsedTime().asSeconds() >= 2.0f) {
            if (abs(_sprite.getPosition().x - heroPosition.x) < _sprite.getGlobalBounds().width / 2) {
                _velocity.x = 0;
            } else {
                if (_sprite.getPosition().x < heroPosition.x) {
                    _velocity.x = 3.5f; // Mover hacia la derecha
                    _sprite.setScale(1, 1); // Mantener la orientación normal del sprite
                } else if (_sprite.getPosition().x > heroPosition.x) {
                    _velocity.x = -3.5f; // Mover hacia la izquierda
                    _sprite.setScale(-1, 1); // Invertir el sprite horizontalmente
                }
            }
        }
    } else {
        _velocity.x = 0; // Quedarse quieto si el héroe está fuera del rango de detección
        _isDetected = false; // Resetear la detección si el héroe está fuera del rango
    }
    if(isPlatformBelow(platforms)==false){
        _velocity.x = 0;
    }
    _velocity.y = _verticalSpeed;
    _sprite.move(_velocity);
    resolveCollisions(platforms);


}

void Fall::resolveCollisions(const vector<sf::FloatRect>& platforms) {
    _onGround = false;
    sf::FloatRect enemyBounds = _sprite.getGlobalBounds();

    for (const auto& platform : platforms) {
        if (enemyBounds.intersects(platform)) {
            if (_verticalSpeed >= 0) {
                _sprite.setPosition(_sprite.getPosition().x, platform.top-36);
                _verticalSpeed = 0;
                _onGround = true;
            }
            break;
        }
    }



}



void Fall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}


#endif // CLSENEMIGOFALL_H_INCLUDED
