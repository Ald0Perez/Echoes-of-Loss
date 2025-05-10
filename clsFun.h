#ifndef CLSFUN_H_INCLUDED
#define CLSFUN_H_INCLUDED

class Fungu : public Fungus {
public:
    Fungu(const string& textureFile = "enemigos/Nivel 1/Fungus/fungus.png", sf::Vector2f v = {2, 2})
        : Fungus(textureFile, v) {
    }
};

#endif // CLSFUN_H_INCLUDED
