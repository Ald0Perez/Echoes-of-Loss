#ifndef CLSCILI_H_INCLUDED
#define CLSCILI_H_INCLUDED

class Cili : public Enemigo {
public:
    Cili(int h = 1, int d = 1, const string& textureFile = "enemigos/Nivel 1/Cili/Cili.png", sf::Vector2f v = {2,2}, float dr = 200.0f)
        : Enemigo(h, d, textureFile, v, dr) {
    }
};

#endif // CLSCILI_H_INCLUDED
