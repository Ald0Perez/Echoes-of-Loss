#ifndef CLSPISO_H_INCLUDED
#define CLSPISO_H_INCLUDED

using namespace std;

class Piso : public sf::Drawable{
private:
    ///Sprite del piso
    sf::Sprite _sprite;
    ///Textura del piso
    sf::Texture _texture;
public:
    ///Setear textura
    void setTexture(const string& textureFile);
    ///Setear la posicion
    void setPosition(float x, float y);
    ///Devuelve la posicion actual del sprite del piso
    sf::Vector2f getPosition() const;
    ///Devuelve la hitbox
    sf::FloatRect getHitBox() const;
    ///Update de la clase piso
    void update();
    ///Metodo que se utiliza para dibujar los bloques
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

void Piso::setTexture(const string& textureFile) {
    ///Cargar textura
    _texture.loadFromFile(textureFile);
    ///Setear textura al sprite
    _sprite.setTexture(_texture);
}

void Piso::setPosition(float x, float y) {
    ///Setear posicion
    _sprite.setPosition(x, y);
}

sf::Vector2f Piso::getPosition() const {
    ///Devuelve la posicion
    return _sprite.getPosition();
}

///Aunque esté vacio el update es crucial para hacer operaciones de mantenimiento de estado
///Todas las clases tienen update.
void Piso::update() {
    ///Update del piso
}

sf::FloatRect Piso::getHitBox() const {
    ///Devuelve la hitbox
    return _sprite.getGlobalBounds();
}

void Piso::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    ///Dibuja los bloques
    target.draw(_sprite, states);
}
#endif // CLSPISO_H_INCLUDED
