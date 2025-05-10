#ifndef CLSINTRO_H_INCLUDED
#define CLSINTRO_H_INCLUDED

class Intro {
private:
    ///TEXTURA DE PANTALLA EN NEGRO
    sf::Texture texture;
    sf::Sprite sprite;
    ///TEXTURA DE SFML
    sf::Texture sfmlTexture;
    sf::Sprite sfmlSprite;
    ///TEXTURA DEL NOMBRE DEL JUEGO
    sf::Texture gameNameTexture;
    sf::Sprite gameNameSprite;
    ///Definir reloj de la biblioteca SFML para calcular el tiempo
    sf::Clock clock;
    ///Definir el SoundBuffer y asignarlo a sound
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
public:
    ///Constructor
    Intro();
    ///Cargar texturas a los Sprites
    void loadTextures();
    ///Reproducir el sonido de Sound
    void playSound();
    ///Codigo principal para que corra en window
    void run(sf::RenderWindow &window);
};

Intro::Intro() {
    ///Cargar texturas
    loadTextures();
    ///Asignacion de sonido
    soundBuffer.loadFromFile("logos/sonido.wav");
    sound.setBuffer(soundBuffer);
}

void Intro::playSound(){
///Reproducir sonido
sound.play();
}

void Intro::loadTextures() {
    ///Asignación de texturas
    texture.loadFromFile("logos/1.jpg");
    sprite.setTexture(texture);

    sfmlTexture.loadFromFile("logos/2.jpg");
    sfmlSprite.setTexture(sfmlTexture);

    gameNameTexture.loadFromFile("logos/3.jpg");
    gameNameSprite.setTexture(gameNameTexture);
}

void Intro::run(sf::RenderWindow &window) {
    ///Reiniciar reloj para que empiece de 0
    clock.restart();
    ///Meterse en el while y calcular los segundos del clock
    while (clock.getElapsedTime().asSeconds() < 1) {
        ///Limpia la ventana de lo que haya existido previamente
        window.clear();
        ///Dibuja el sprite en la ventana
        window.draw(sprite);
        ///Muestra lo que se dibujo en pantalla
        window.display();
    }

    clock.restart();
    ///Ahora le agregamos un sonido a esta y a la siguiente imagen porque estas si tienen contenido
    playSound();
    while (clock.getElapsedTime().asSeconds() < 1) {
        window.clear();
        window.draw(sfmlSprite);
        window.display();
    }

    clock.restart();
    playSound();
    while (clock.getElapsedTime().asSeconds() < 1) {
        window.clear();
        window.draw(gameNameSprite);
        window.display();
    }
}

#endif // CLSINTRO_H_INCLUDED
