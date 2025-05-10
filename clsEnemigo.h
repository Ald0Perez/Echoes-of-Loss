#ifndef CLSENEMIGO_H_INCLUDED
#define CLSENEMIGO_H_INCLUDED

using namespace std;

float distance(const sf::Vector2f& point1, const sf::Vector2f& point2) {
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

class Enemigo : public sf::Drawable {
private:
    int _health;
    int _damage;
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float _verticalSpeed;
    bool _onGround;
    bool _isDead;
    float detectionRadius;
    void setOriginToCenter();
public:
    Enemigo(){}
    Enemigo(int h, int d, const string& textureFile, sf::Vector2f v, float dr) {
        _health = h;
        _damage = d;
        _texture.loadFromFile(textureFile);
        _sprite.setTexture(_texture);
        setOriginToCenter(); // Establecer el origen al centro
        _velocity = v;
        _verticalSpeed = 0;
        _isDead = false;
        _onGround = false;
        detectionRadius = dr;
    }
    sf::FloatRect getLimite(){return _sprite.getGlobalBounds();}
    int getHealth() { return _health; }
    int getDamage() { return _damage; }
    sf::FloatRect getHitBox() {
        return _sprite.getGlobalBounds();
    }
        float getSuperior(){
     return _sprite.getPosition().y;
    }

    void setHealth(int h) { _health = h; }
    void setDamage(int d) { _damage = d; }
    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    void update(const vector<sf::FloatRect>& platforms, const sf::Vector2f& heroPosition);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void resolveCollisions(const vector<sf::FloatRect>& platforms);
};

void Enemigo::setOriginToCenter() {
    sf::FloatRect bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Enemigo::update(const vector<sf::FloatRect>& platforms, const sf::Vector2f& feinPosicion) {
    if (!_onGround) {
        _verticalSpeed += GRAVITY;
    } else {
        _verticalSpeed = 0;
    }

    float distancia = distance(_sprite.getPosition(), feinPosicion);
    if (distancia <= detectionRadius) {
        if (abs(_sprite.getPosition().x - feinPosicion.x) < _sprite.getGlobalBounds().width / 2) {
            _velocity.x = 0;
        } else {
            if (_sprite.getPosition().x < feinPosicion.x) {
                _velocity.x = 2.5f; // Mover hacia la derecha
                _sprite.setScale(1, 1); // Mantener la orientación normal del sprite
            } else if (_sprite.getPosition().x > feinPosicion.x) {
                _velocity.x = -2.5f; // Mover hacia la izquierda
                _sprite.setScale(-1, 1); // Invertir el sprite horizontalmente
            }
        }
    } else {
        _velocity.x = 0; // Quedarse quieto si el héroe está fuera del rango de detección
    }

    _velocity.y = _verticalSpeed;
    _sprite.move(_velocity);
    resolveCollisions(platforms);

    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
}

void Enemigo::resolveCollisions(const vector<sf::FloatRect>& platforms) {
    _onGround = false;
    sf::FloatRect enemyBounds = _sprite.getGlobalBounds();

    for (const auto& platform : platforms) {
        if (enemyBounds.intersects(platform)) {
            if (_verticalSpeed >= 0) {
                _sprite.setPosition(_sprite.getPosition().x, platform.top-15);
                _verticalSpeed = 0;
                _onGround = true;
            }
            break;
        }
    }
}

void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

#endif

