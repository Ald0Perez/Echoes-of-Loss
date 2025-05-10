#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

#include "clsPiso.h"
#include "clsGlobal.h"
#include "clsAnimacion.h"
#include "clsHeroe.h"
#include "clsEnemigo.h"
#include "clsEnemigoFall.h"
#include "clsEnemigoFungus.h"
#include "clsFall.h"
#include "clsFun.h"
#include "clsObstaculo.h"
#include "clsMurcielago.h"
#include "clsCili.h"
#include "clsNivel.h"
#include "clsIntro.h"
#include "clsMenu.h"

using namespace std;

///IMPORTANTE, ir al proyecto principal, click derecho, build options, le dan a debug y ponen sfml-audio-d

int menu(){
 sf::RenderWindow window(sf::VideoMode(1080, 720), "Echoes of Loss");
    window.setFramerateLimit(60);


    // Cargar la imagen de fondo del menú
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("menu/MENU.jpg")) {
        cerr << "Error al cargar la imagen de fondo del menú." << endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Inicializar y configurar el menú
    Menu menu(window.getSize().x, window.getSize().y);
    menu.playMusic();

    // Instancia del nivel de juego
    Nivel nivel;

    bool inOptionsMenu = false;
    bool returnToMenu = false;
      bool volvio=false;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (inOptionsMenu) {
                // Manejar eventos del menú de opciones
                if (event.type == sf::Event::MouseMoved) {
                    menu.handleOptionsMouseMove(event.mouseMove.x, event.mouseMove.y);
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        menu.handleOptionsClick(event.mouseButton.x, event.mouseButton.y);
                        if (menu.isBackSelected(event.mouseButton.x, event.mouseButton.y)) {
                            inOptionsMenu = false;
                        }
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    inOptionsMenu = false;
                }
            } else {
                // Manejar eventos del menú principal
                if (event.type == sf::Event::MouseMoved) {
                    menu.handleMouseMove(event.mouseMove.x, event.mouseMove.y);
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        menu.handleMouseClick(event.mouseButton.x, event.mouseButton.y);
                        switch (menu.getSelectedItemIndex()) {
                            case 0:
                                // Iniciar juego
                                menu.stopMusic();
                                volvio=nivel.run(window, returnToMenu);
                                if (volvio) {
                                    return 2;
                                }
                                break;
                            case 1:
                                // Ir a opciones
                                inOptionsMenu = true;
                                break;
                            case 2:
                                // Salir del juego
                                window.close();
                                return 1;
                                break;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite); // Dibujar la imagen de fondo
        if (inOptionsMenu) {
            menu.drawOptions(window); // Dibujar menú de opciones
        } else {
            menu.draw(window); // Dibujar menú principal
        }
        window.display();
    }
    return 0;
}
int main() {
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Echoes of Loss");
    window.setFramerateLimit(60);
   int retornar=2;
    Intro intr;
    intr.run(window);
    window.close();
while(retornar==2){
       retornar=menu();

}
    return 0;
}
