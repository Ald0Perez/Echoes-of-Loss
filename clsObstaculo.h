#ifndef CLSOBSTACULO_H_INCLUDED
#define CLSOBSTACULO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace std;

class Obstaculo : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float _verticalSpeed;
    void setOriginToCenter();
    bool cambio;
    float distanciaRecorrida;
    float maxDistancia;

public:
    Obstaculo() {}
    Obstaculo(const string& textureFile, sf::Vector2f v) {
        _texture.loadFromFile(textureFile);
        _sprite.setTexture(_texture);
        setOriginToCenter();
        _velocity = sf::Vector2f(0, v.y); // Solo velocidad vertical
        _verticalSpeed = 0;
        cambio = false;
        distanciaRecorrida = 0.0f;
        maxDistancia = 200.0f;
    }

    sf::FloatRect getLimite() { return _sprite.getGlobalBounds(); }
    void setMaxDistancia(float maxDis){maxDistancia=maxDis;}
    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    void update(const vector<sf::FloatRect>& platforms);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void choque(const vector<sf::FloatRect>& platforms);
};

void Obstaculo::setOriginToCenter() {
    sf::FloatRect bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Obstaculo::update(const vector<sf::FloatRect>& platforms) {
    choque(platforms);

    // Movimiento básico
    if (_velocity.y == 0) {
        _velocity.y = 2.7f; // Valor inicial de la velocidad
    }

    // Cambiar dirección si se produce un choque o se alcanza la distancia máxima
    if (cambio || distanciaRecorrida >= maxDistancia) {
        _velocity.y = -_velocity.y;

        distanciaRecorrida = 0.0f;
    }

    // Mover el obstáculo y actualizar la distancia recorrida
    _sprite.move(_velocity);
    distanciaRecorrida += std::abs(_velocity.y); // Sumar la distancia recorrida en valor absoluto
}

void Obstaculo::choque(const vector<sf::FloatRect>& platforms) {
    cambio = false;

    for (const auto& platform : platforms) {
        if (_sprite.getGlobalBounds().intersects(platform)) {
            cambio = true;
            break;
        }
    }
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

#endif // CLSOBSTACULO_H_INCLUDED
