#ifndef CLSMURCIELAGO_H_INCLUDED
#define CLSMURCIELAGO_H_INCLUDED

class Mur : public Obstaculo {
public:
    Mur(const string& textureFile = "enemigos/Nivel 1/Murcielago/murcielago.png", sf::Vector2f v = {2,2})
        : Obstaculo(textureFile, v) {
    }
};

#endif // CLSMURCIELAGO_H_INCLUDED
