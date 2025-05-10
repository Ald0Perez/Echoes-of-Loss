#ifndef CLSANIMACION_H_INCLUDED
#define CLSANIMACION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

class Animacion {
private:
    vector<Texture> frames;
    int frameActual;
    float duracionFrame;
    Clock relojAnimacion;

public:
    Animacion(const string& carpeta, int numFrames, float duracion) {
        frameActual = 0;
        duracionFrame = duracion;

        for (int i = 0; i < numFrames; ++i) {
            Texture textura;
            string ruta = carpeta + to_string(i + 1) + ".png";

            if (!textura.loadFromFile(ruta)) {
                cerr << "Error al cargar la textura: " << ruta << endl;
                // Manejo de error si no se puede cargar alguna textura
            }
            frames.push_back(textura);
        }
    }

    void actualizar() {
        if (relojAnimacion.getElapsedTime().asSeconds() > duracionFrame) {
            frameActual = (frameActual + 1) % frames.size();
            relojAnimacion.restart();
        }
    }

    void setFrame(int frame) {
        if (frame >= 0 && frame < frames.size()) {
            frameActual = frame;
        }
    }

    void setFrameDuracion(float duracion) {
        duracionFrame = duracion;
    }

    Texture& getFrameTexture() {
        return frames[frameActual];
    }
};



#endif // CLSANIMACION_H_INCLUDED
