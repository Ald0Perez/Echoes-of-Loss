#ifndef CLSMENU_H_INCLUDED
#define CLSMENU_H_INCLUDED

using namespace std;

class Menu {
private:
    ///Seleccionador de items del menu
    int selectedItemIndex;
    ///Fuente para los textos
    sf::Font font;
    ///Vector que contiene elementos de texto del menu
    vector<sf::Text> menuItems;
    ///Numero de elementos del menu
    const int MAX_NUMBER_OF_ITEMS = 3; // Cambiado a 3
    ///Musica
    sf::Music music;
    /// Texto para la flechita de opciones
    sf::Text arrowText;

    ///Textura de Opciones
    sf::Texture opciones;
    sf::Sprite textureOpciones;

    /// Rectángulos para los controles de volumen
    sf::RectangleShape musicBackgroundSlider; /// Fondo blanco del control de volumen de música
    sf::RectangleShape musicVolumeSlider;     /// Control deslizante negro del volumen de música
    float musicVolume;

    sf::RectangleShape effectsBackgroundSlider; /// Fondo blanco del control de volumen de efectos
    sf::RectangleShape effectsVolumeSlider;     /// Control deslizante negro del volumen de efectos
    float effectsVolume;

    ///Texto para volver al menu
    sf::Text volverText;
    ///Bandera para volver al menu
    bool isBackToMainMenu;

    sf::SoundBuffer optionHoverBuffer;
    sf::Sound optionHoverSound;
    sf::SoundBuffer optionClickBuffer;
    sf::Sound optionClickSound;

    /// Bandera para evitar que el sonido de hover se reproduzca continuamente
    bool isHoverSoundPlaying;
public:
    ///Constructor
    Menu(float width, float height);
    ///Dibuja elementos en la pantalla
    void draw(sf::RenderWindow &window);
    ///Maneja el movimiento del mouse
    void handleMouseMove(float x, float y);
    ///Maneja el click del mouse
    void handleMouseClick(float x, float y);
    ///Get del índice del elemento del menú seleccionado
    int getSelectedItemIndex() const;
    ///Reproducir música
    void playMusic();
    ///Parar musica
    void stopMusic();
    ///Dibuja elementos de las opciones como la funcion anterior llamada draw
    void drawOptions(sf::RenderWindow &window);
    ///Maneja eventos del click del mouse en opciones
    void handleOptionsClick(float x, float y);
    ///Maneja el movimiento del mouse en opciones
    void handleOptionsMouseMove(float x, float y);
    ///Confirma si el texto volver fue clickeado
    bool isBackSelected(float x, float y);
};

Menu::Menu(float width, float height) {
    font.loadFromFile("fuente/Gamerock.otf");

    vector<string> itemNames = {"Jugar", "Opciones", "Salir"};
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        sf::Text text;
        text.setFont(font);
        text.setFillColor(sf::Color::White);
        text.setString(itemNames[i]);
        text.setPosition(sf::Vector2f(width / 2.3, height / (MAX_NUMBER_OF_ITEMS + 5) * (i + 3.8)));
        menuItems.push_back(text);
    }
    selectedItemIndex = -1;

    music.openFromFile("sonidos/menu/MENU.wav");
    // Configurar el texto de la flechita
    arrowText.setFont(font);
    arrowText.setString("->");
    arrowText.setFillColor(sf::Color::Black);

    // Configurar los sliders de volumen de música
    musicVolume = 50.0f;
    musicBackgroundSlider.setSize(sf::Vector2f(200, 20));
    musicBackgroundSlider.setFillColor(sf::Color::White);
    musicBackgroundSlider.setPosition(sf::Vector2f(width / 2.3, height / 2.7));

    musicVolumeSlider.setSize(sf::Vector2f(musicVolume * 2, 20));
    musicVolumeSlider.setFillColor(sf::Color::Black);
    musicVolumeSlider.setPosition(sf::Vector2f(width / 2.3, height / 2.7));

    // Configurar los sliders de volumen de efectos
    effectsVolume = 50.0f;
    effectsBackgroundSlider.setSize(sf::Vector2f(200, 20));
    effectsBackgroundSlider.setFillColor(sf::Color::White);
    effectsBackgroundSlider.setPosition(sf::Vector2f(width / 2.3, height / 2.15));

    effectsVolumeSlider.setSize(sf::Vector2f(effectsVolume * 2, 20));
    effectsVolumeSlider.setFillColor(sf::Color::Black);
    effectsVolumeSlider.setPosition(sf::Vector2f(width / 2.3, height / 2.15));

    opciones.loadFromFile("menu/OPCIONES/opciones.jpg");
    textureOpciones.setTexture(opciones);

    volverText.setFont(font);
    volverText.setString("Volver");
    volverText.setFillColor(sf::Color::White);
    volverText.setPosition(sf::Vector2f(width / 2.1, height / 1.2));

    music.setVolume(musicVolume);

    // Cargar sonidos

    optionClickBuffer.loadFromFile("menu/Efecto1.wav");
    optionClickSound.setBuffer(optionClickBuffer);

    // Inicializar bandera de sonido de hover
    isHoverSoundPlaying = false;
}

void Menu::playMusic() {
    music.play();
}
void Menu::stopMusic() {
    music.stop();
}

///MENU PRINCIPAL INICIO

void Menu::draw(sf::RenderWindow &window) {
    for (const auto &item : menuItems) {
        window.draw(item);
    }
    if (selectedItemIndex != -1) {
        window.draw(arrowText);
    }
}

void Menu::handleMouseMove(float x, float y) {
    bool isMouseOverItem = false;
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        if (menuItems[i].getGlobalBounds().contains(x, y)) {
            isMouseOverItem = true;
            if (selectedItemIndex != i) {
                if (selectedItemIndex != -1) {
                    menuItems[selectedItemIndex].setFillColor(sf::Color::White);
                }
                selectedItemIndex = i;
                menuItems[selectedItemIndex].setFillColor(sf::Color::Black);

                // Posicionar la flechita a la izquierda del texto seleccionado
                arrowText.setPosition(menuItems[selectedItemIndex].getPosition().x - 30,
                                      menuItems[selectedItemIndex].getPosition().y);

                // Reproducir sonido de hover
                if (!isHoverSoundPlaying) {
                    optionHoverSound.play();
                    isHoverSoundPlaying = true;
                }
            }
        }
    }
    if (!isMouseOverItem && selectedItemIndex != -1) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex = -1;
        isHoverSoundPlaying = false;  // Restablecer la bandera cuando el mouse sale del área de los ítems
    }
}

void Menu::handleMouseClick(float x, float y) {
    // Acción a realizar dependiendo del elemento seleccionado
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        if (menuItems[i].getGlobalBounds().contains(x, y)) {
            // Reproducir sonido de clic
            optionClickSound.play();
            selectedItemIndex = i;
            break;
        }
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

///MENU PRINCIPAL FIN

///MENU OPCIONES INICIO

void Menu::drawOptions(sf::RenderWindow &window) {

    if (volverText.getFillColor() == sf::Color::Black) {
        window.draw(arrowText);
    }
    window.draw(textureOpciones);
    window.draw(musicBackgroundSlider);
    window.draw(musicVolumeSlider);
    window.draw(effectsBackgroundSlider);
    window.draw(effectsVolumeSlider);
    window.draw(volverText);
}

void Menu::handleOptionsClick(float x, float y) {
    // Verificar si se hizo clic dentro del área del slider de música
    if (musicBackgroundSlider.getGlobalBounds().contains(x, y)) {
        float newVolume = ((x - musicBackgroundSlider.getPosition().x) / musicBackgroundSlider.getSize().x) * 100;
        musicVolume = newVolume;
        musicVolumeSlider.setSize(sf::Vector2f(musicVolume * 2, 20)); // Actualizar tamaño del volumen negro
        music.setVolume(musicVolume);
        // Reproducir sonido cuando se hace clic en el slider de música
        optionClickSound.play();
    }
    // Verificar si se hizo clic dentro del área del slider de efectos
    else if (effectsBackgroundSlider.getGlobalBounds().contains(x, y)) {
        float newVolume = (x - effectsBackgroundSlider.getPosition().x) / 2.0f;
        effectsVolume = max(0.0f, min(100.0f, newVolume));
        effectsVolumeSlider.setSize(sf::Vector2f(effectsVolume * 2, effectsBackgroundSlider.getSize().y));
        optionHoverSound.setVolume(effectsVolume);
        optionClickSound.setVolume(effectsVolume);
        optionClickSound.play();
    }

    if (volverText.getGlobalBounds().contains(x, y)) {
        // Aquí puedes establecer una bandera o realizar la acción de volver al menú principal
        isBackToMainMenu = true;  // Define esta variable en tu clase Menu
        // Reproducir sonido cuando se hace clic en "Volver"
        optionClickSound.play();
    }
}

void Menu::handleOptionsMouseMove(float x, float y) {
    bool isMouseOverVolverText = volverText.getGlobalBounds().contains(x, y);

    if (isMouseOverVolverText) {
        volverText.setFillColor(sf::Color::Black);
        // Reproducir sonido cuando el mouse pasa por encima de "Volver"
        if (!isHoverSoundPlaying) {
            optionHoverSound.play();
            isHoverSoundPlaying = true;
        }
    } else {
        volverText.setFillColor(sf::Color::White);
        isHoverSoundPlaying = false;  // Restablecer la bandera cuando el mouse sale del área de "Volver"
    }
}

bool Menu::isBackSelected(float x, float y) {
    return volverText.getGlobalBounds().contains(x, y);
}

///MENU OPCIONES FIN

#endif // CLSMENU_H_INCLUDED
