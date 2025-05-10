#ifndef CLSFALL_H_INCLUDED
#define CLSFALL_H_INCLUDED

class Foll : public Fall {
public:
    Foll(const string& textureFile = "enemigos/Nivel 1/Fall/fall.png", sf::Vector2f v = {2,2}, float dr = 250.0f)
        : Fall(textureFile, v, dr) {
    }
};

#endif // CLSFALL_H_INCLUDED
