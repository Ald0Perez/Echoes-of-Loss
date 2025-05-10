#ifndef CLSHEROE_H_INCLUDED
#define CLSHEROE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Heroe : public sf::Drawable {
private:
    ///vida
    int _health;
    int _maxHealth;
    sf::Sprite _healthSprite;
    vector<sf::Texture> _healthTextures;
    //Fein
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float verticalSpeed;
    bool _onGround;
    bool _cayendo;
    bool _isDead;
    bool _isInvulnerable;
    sf::Clock _invulnerability;
    ///variables para las animaciones
    Animacion runAnimation;
    ///Variables para sonidos
    sf::SoundBuffer caminarSonido;
    sf::Sound caminar;
    bool llave;
    int llaves;
    /// Constante para la detección de colisiones desde arriba
    const float threshold = 10.0f;
public:
    Heroe() : runAnimation("animaciones/fein/correr/", 6, 0.1f) {
        _maxHealth = 3;
        _health = 3;
        _velocity = {4, 4};

        for (int i = 0; i <= _maxHealth; ++i) {
            sf::Texture texture;
            if (!texture.loadFromFile("personaje/VIDA PERSONAJE/vidas" + to_string(i) + "_GAME.png")) {
                cout << "No se encontró: vida" << i << ".png" << endl;
            }
            _healthTextures.push_back(texture);
        }


        _healthSprite.setTexture(_healthTextures[_maxHealth]);
        _healthSprite.setPosition(0, 0);

        _texture.loadFromFile("personaje/Fein/pj.png");
        _sprite.setTexture(_texture);
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
        verticalSpeed = 0;
        _onGround = false;
        _cayendo=false;
        _isInvulnerable = false;
        caminarSonido.loadFromFile("sonidos/correr1.wav");
        caminar.setBuffer(caminarSonido);
        llaves = 0;
        llave= false;
    }

    //gets
    bool getDead() { return _isDead; }
    float getVerticalSpeed() { return verticalSpeed; }
    float getX() { return _velocity.x; }
    int getHealth() { return _health; }
    sf::FloatRect getHitBox();
    float getInferior() {return _sprite.getPosition().y + _sprite.getGlobalBounds().height;}
    sf::Vector2f getPosition() { return _sprite.getPosition(); }
    bool getOnGround()const;
    bool getCayendo();
    float getPositionx() { return _sprite.getPosition().x; }
    float getPositiony() { return _sprite.getPosition().y; }
    float getglobalboundswidth() { return _sprite.getGlobalBounds().width; }
    float getglobalboundsheight() { return _sprite.getGlobalBounds().height; }
    sf::FloatRect getLimites(){return _sprite.getGlobalBounds();}
    bool getIsInvulnerable() const { return _isInvulnerable; }
    bool getHasKey() const { return llave; }
    int getHasKeys() {return llaves;}

   //sets
    void setLlaves(){llaves++;}
    void setHealth(int h) { _health = h; }
    void setPosition(float x, float y);
    void setTexture(sf::Texture t) { _sprite.setTexture(t); }
    void setVelocityX(float vx) { _velocity.x = vx; _sprite.move(_velocity.x, 0); }
    void setVelocityY(float vy) {verticalSpeed = vy; _sprite.move(0,_velocity.y); }

    //funciones checkKeyCollision
    bool heckKeyCollision(const sf::Sprite keySprite);
    void updateKeySprite(const sf::View& view);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(const vector<sf::FloatRect>& platforms);
    void resolveCollisions(const vector<sf::FloatRect>& platforms);
    void updateHealthSprite();
    void takeDamage(int damage);
    void checkEnemyCollision(vector<sf::FloatRect>& enemigos);
    void updateHealthBarPosition(const sf::View& view);
};

sf::FloatRect Heroe::getHitBox() {
    return _sprite.getGlobalBounds();
}

bool Heroe::getOnGround()const{
    return _onGround;
}

bool Heroe::getCayendo() {
    _cayendo = (verticalSpeed > 0);
    return _cayendo;
}

void Heroe::update(const vector<sf::FloatRect>& platforms) {
    if (_isInvulnerable && _invulnerability.getElapsedTime().asSeconds() >= 4) {
        _isInvulnerable = false;
    }
    _velocity.x = 0;
    bool movingLeft = false;
    bool movingRight = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (verticalSpeed == 0 && _onGround) { // Asegurarse de que esté en el suelo y no saltando
                if (caminar.getStatus() != sf::Sound::Playing) { // Evitar reproducir múltiples veces simultáneamente
                    caminar.play();
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
            _velocity.x = 0;
    }else{
        _velocity.x = -4;
        runAnimation.actualizar();
        _sprite.setTexture(runAnimation.getFrameTexture());
        movingLeft = true;
    }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (verticalSpeed == 0 && _onGround) { // Asegurarse de que esté en el suelo y no saltando
                if (caminar.getStatus() != sf::Sound::Playing) { // Evitar reproducir múltiples veces simultáneamente
                    caminar.play();
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
            _velocity.x = 0;
            caminar.stop();
    }else{
        _velocity.x = 4;
        runAnimation.actualizar();
        _sprite.setTexture(runAnimation.getFrameTexture());
        movingRight = true;
    }
    }

    // Si no se está moviendo ni a la izquierda ni a la derecha, usar la textura estática
    if (!movingLeft && !movingRight) {
        _sprite.setTexture(_texture);
    }

    if (_onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        verticalSpeed = -7.25f; // Ajusta este valor según la altura de salto deseada
        _onGround = false;
        cout<<getPositionx()<<","<<getPositiony()<<endl;
    }

    if (!_onGround) {
        verticalSpeed += GRAVITY;
    } else {
        verticalSpeed = 0;
    }

    // Resolver colisiones
    resolveCollisions(platforms);

    // Cambiar la escala del sprite según la dirección del movimiento
    if (_velocity.x < 0) {
        _sprite.setScale(-1, 1);
    } else if (_velocity.x > 0) {
        _sprite.setScale(1, 1);
    }

    // Mantener al personaje dentro de los límites de la pantalla
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if(!getHasKey()){
        if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 8688) {
        _sprite.setPosition(8688 - (_sprite.getGlobalBounds().width-_sprite.getOrigin().x), _sprite.getPosition().y);
    }
    }else{

    }

    updateHealthSprite();
}

void Heroe::takeDamage(int damage) {
    if (!_isInvulnerable) {
        _health -= damage;
        if (_health < 0) _health = 0;
        updateHealthSprite();
        _isInvulnerable = true;
        _invulnerability.restart();
    }
}

bool Heroe::heckKeyCollision(const sf::Sprite llaveSprite) {
    if (_sprite.getGlobalBounds().intersects(llaveSprite.getGlobalBounds())) {
        llave = true;
        return true;
    }
}

void Heroe::updateHealthSprite() {
    if (_health >= 0 && _health <= _maxHealth) {
        _healthSprite.setTexture(_healthTextures[_health]);
    }
}

void Heroe::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

void Heroe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
    target.draw(_healthSprite, states);
}

void Heroe::resolveCollisions(const vector<sf::FloatRect>& platforms) {
    _onGround = false;
    sf::FloatRect heroeBounds = _sprite.getGlobalBounds();
    // sf::Vector2f previousPosition = _sprite.getPosition(); // Eliminado para evitar advertencia de variable no utilizada

    // Comprobar colisiones horizontales
    _sprite.move(_velocity.x, 0);
    heroeBounds = _sprite.getGlobalBounds();

    for (const auto& platform : platforms) {
        if (heroeBounds.intersects(platform)) {
            if (_velocity.x > 0) { // Moviéndose hacia la derecha
                _sprite.setPosition(platform.left - heroeBounds.width + 20, _sprite.getPosition().y);
                cout << "COLISION" << endl;
            } else if (_velocity.x < 0) { // Moviéndose hacia la izquierda
                _sprite.setPosition(platform.left + heroeBounds.width + 10, _sprite.getPosition().y);

            }
            _velocity.x = 0; // Detener movimiento horizontal al colisionar
            break;
        }
    }


    // Comprobar colisiones verticales
    _sprite.move(0, verticalSpeed);
    heroeBounds = _sprite.getGlobalBounds();

    for (const auto& platform : platforms) {
        if (heroeBounds.intersects(platform)) {
            if (verticalSpeed > 0) { // Moviéndose hacia abajo
                _sprite.setPosition(_sprite.getPosition().x, platform.top);
                _onGround = true;
            } else if (verticalSpeed < 0) { // Moviéndose hacia arriba
                _sprite.setPosition(_sprite.getPosition().x, platform.top + platform.height + 60);
            }
            verticalSpeed = 0; // Detener movimiento vertical al colisionar
            break;
        }
    }
}

void Heroe::checkEnemyCollision(vector<sf::FloatRect>& enemigos) {
    sf::FloatRect heroeBounds = _sprite.getGlobalBounds();

    for (auto& enemigo : enemigos) {
        sf::FloatRect enemyBounds = enemigo;

        if (heroeBounds.intersects(enemyBounds)) {
            float heroeBottom = _sprite.getPosition().y + _sprite.getGlobalBounds().height;
            float enemyTop = enemigo.top;

            if (heroeBottom <= enemyTop + threshold) {
                // Aquí deberías eliminar al enemigo del vector o marcarlo como muerto
                // en función de tu diseño de juego.
                cout << "Enemigo eliminado!" << endl;
            } else {
                // Colisión lateral
                if (!_isInvulnerable) {
                    // Ajusta esto según cómo manejes el daño en tu juego
                    takeDamage(1);
                    cout << "Has recibido 1 de daño!" << endl;
                }
            }
        }
    }
}

void Heroe::updateHealthBarPosition(const sf::View& view) {
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewSize = view.getSize();
    _healthSprite.setPosition(viewCenter.x - viewSize.x / 2 + 10, viewCenter.y - viewSize.y / 2 + 10);
}

#endif // CLSHEROE_H_INCLUDED
