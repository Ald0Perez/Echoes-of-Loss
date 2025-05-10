#ifndef CLSENEMIGOFUNGUS_H_INCLUDED
#define CLSENEMIGOFUNGUS_H_INCLUDED

class Fungus : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float _verticalSpeed;
    bool _onGround;
    bool _isDead;
    void setOriginToCenter();
public:
    Fungus() {}
    Fungus(const string& textureFile, sf::Vector2f v) {
        _texture.loadFromFile(textureFile);
        _sprite.setTexture(_texture);
        setOriginToCenter();
        _velocity = v;
        _verticalSpeed = 0;
        _isDead = false;
        _onGround = false;
    }
    sf::FloatRect getLimite(){return _sprite.getGlobalBounds();}

        float getSuperior(){
     return _sprite.getPosition().y;
    }


    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    bool isPlatformBelow(const vector<sf::FloatRect>& platforms);
    void update(const vector<sf::FloatRect>& platforms);
    void resolveCollisions(const vector<sf::FloatRect>& platforms);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
bool Fungus::isPlatformBelow(const vector<sf::FloatRect>& platforms) {
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    sf::FloatRect below(bounds.left, bounds.top + bounds.height + 1, bounds.width, 1); // Un rectángulo justo debajo del enemigo

    for (const auto& platform : platforms) {
        if (below.intersects(platform)) {
            return true;
        }
    }
    return false;
}
void Fungus::setOriginToCenter() {
    sf::FloatRect bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Fungus::update(const vector<sf::FloatRect>& platforms) {
    if (!_onGround) {
        _verticalSpeed += GRAVITY;
    } else {
        _verticalSpeed = 0;
    }

    // Movimiento horizontal básico
    if (_velocity.x == 0) {
        _velocity.x = 2.7f; // Valor inicial de la velocidad
    }

    if (!isPlatformBelow(platforms)) {
        // Cambiar dirección si no hay plataforma debajo
        _velocity.x = -_velocity.x;
        _sprite.setScale(_sprite.getScale().x * -1, _sprite.getScale().y); // Invertir el sprite horizontalmente
    }



    _velocity.y = _verticalSpeed;
    _sprite.move(_velocity);
    resolveCollisions(platforms);


}

void Fungus::resolveCollisions(const vector<sf::FloatRect>& platforms) {
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

void Fungus::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}


#endif // CLSENEMIGOFUNGUS_H_INCLUDED
