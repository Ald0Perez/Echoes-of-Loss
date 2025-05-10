#ifndef CLSNIVEL_H_INCLUDED
#define CLSNIVEL_H_INCLUDED

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

class Nivel {
private:
    ///Crea al personaje principal o sea Fein.
    Heroe fein;
    Enemigo enemigo;
    sf::Texture cartel_text;
    sf::Sprite cartel;
    ///Puerta
    sf::Texture puerta_text;
    sf::Sprite puerta;
    ///Casa
    sf::Texture casa_text;
    sf::Sprite casa;
    ///Crea a uno de los enemigos.
    Cili enem1,enem2,enem3,enem4,enem5,enem6,enem8,enem9,enem10,enem11,enem12,enem13,enem14,enem15,enem16;
     ///Creo a los fungus
    Fungu fun1,fun2,fun3,fun4,fun5,fun6,fun7,fun8,fun9,fun10,fun11,fun12,fun13,fun14,fun15,fun16,fun17,fun18,fun19,fun20,fun21;
    Fungus enemigo_;

    ///Creo los falls
    Foll fall1, fall2;
    Fall enemigoF;

    ///OBSTACULOS
    Mur mur1,mur2,mur3,mur4,mur5,mur6,mur7,mur8,mur9,mur10,mur11,mur12,mur13,mur14,mur15,mur16,mur17,mur18,mur19,mur20,mur21,mur22,mur23,mur24,mur25;
    Obstaculo obss;
    ///Creación de pisos con distintas texturas.
    Piso piso1, tierra;
    ///Creacion de pisos flotantes con distintass textruas
    Piso bloqueFlotante1, bloqueFlotante2, bloqueFlotante3, tierraFlotante;
    ///Textura del cielo.
    sf::Texture cielo_text;
    ///Sprite del cielo donde va a ir la textura.
    sf::Sprite cielo;
    ///Texturas diferentes de nubes para hacer efecto parallax.
    sf::Texture nubes_text1, nubes_text2, nubes_text3;
    ///Sprites de las nubes mencionadas arriba
    sf::Sprite nubes1, nubes2, nubes3;
    ///Ofsset para controlar la posicion vertical de las nubes.
    float nubesOffset;
    ///Vector de tipo FloatRect para almacenar plataformas (pisos) del nivel.
    vector<sf::FloatRect> platforms;
    ///Vector de tipo enemigo que va a almacenar los enemigos del nivel.
    vector<Enemigo> enemigos;
    ///vector de los enemigos fungus
    vector<Fungus> funEnemigos;
    ///vector de los falls
    vector<Fall> fallEnemigos;
    ///vector de murcielagos
    vector<Obstaculo> vecobstaculos;
    sf::SoundBuffer killSound;
    sf::Sound kill;
    ///Variable que ayuda al manejo de cámara del juego.
    sf::View view;

    ///Variables del menú de pausa
    bool isPaused;
    sf::RectangleShape overlay;
    sf::Text pauseMenuText;
    sf::Font font;

    /// Variables para la pantalla de "Perdiste"
    bool isGameOver;
    sf::RectangleShape gameOverOverlay;
    sf::Text gameOverText;
    /// Variables para la pantalla de "GANASTE"
    bool win;
    sf::RectangleShape gameWinOverlay;
    sf::Text gameWinText;
    ///Musica del nivel
    sf::Music backgroundMusic;
    ///Llave
    sf::Texture llave_text;
    sf::Sprite llave;
    sf::SoundBuffer keyBuffer;
    sf::Sound key;
    ///WIN
    sf::SoundBuffer winBuffer;
    sf::Sound wins;
    ///GAME OVER
    sf::SoundBuffer gameOverBuffer;
    sf::Sound gameOver;
    ///LLAVE1
    sf::Texture llaveCasa1;
    sf::Sprite llaveCasa1_sprite;
    ///LLAVE2
    sf::Texture llaveCasa2;
    sf::Sprite llaveCasa2_sprite;
    ///LLAVE3
    sf::Texture llaveCasa3;
    sf::Sprite llaveCasa3_sprite;
    ///SONIDO DE DAÑO
    sf::SoundBuffer sonidoVida;
    sf::Sound vida;
    ///CARTEL LLAVE
    sf::Texture cartelLlave_text, cartelLlave2_text,cartelLlave3_text,cartelLlave4_text;
    sf::Sprite cartelLlave, cartelLlave2, cartelLlave3, cartelLlave4;
    ///CARTEL ARRIBA
    sf::Texture cartelArriba_text;
    sf::Sprite cartelArriba;
    ///DECORACION
    sf::Texture arbusto1;
    sf::Sprite arbusto_1;

    sf::Texture arbusto2;
    sf::Sprite arbusto_2;

    sf::Texture cartel_home;
    sf::Sprite cartel_h;

    sf::Texture piedra_g;
    sf::Sprite _piedra_g,_piedra_g2;

    sf::Texture piedra_sapo;
    sf::Sprite _piedra_sapo;

    sf::Texture piedra_sapo_1;
    sf::Sprite _piedra_sapo_1;

    sf::Texture farola;
    sf::Sprite _farola,_farola2,_farola3,_farola4;
public:
    ///Constructor del nivel donde vamos a inicializar muchas de las variables definidas anteriormente.
    Nivel();
    ///Funcion para inicializar posiciones y hitboxs.
    void initializeLevel();
    ///Funcion para manejar eventos de la ventana.
    void processEvents(sf::RenderWindow &window);
    ///Funcion para manejar el estado del nivel.
    void update(sf::RenderWindow &window);
    ///Metodo para renderizar el nivel.
    bool render(sf::RenderWindow &window);
    ///Funcion main que ejecuta el while para que funcione el juego.
    bool run(sf::RenderWindow &window, bool returnMenu);
    ///Funcion para mostrar el menu de pausa.
    void showPauseMenu(sf::RenderWindow &window);
    void handlePauseMenuInput(sf::RenderWindow &window);
    void handleGameOverInput(sf::RenderWindow &window);
    void handleGameOver(sf::RenderWindow &window);
    void handleGameWin(sf::RenderWindow &window);
};

Nivel::Nivel() {
    ///Cargar al sprite la textura del cielo (background)
    cielo_text.loadFromFile("cielo/nivel1/CIELO.jpg");
    cielo.setTexture(cielo_text);

    llave_text.loadFromFile("llave/1.png");
    llave.setTexture(llave_text);
    llave.setPosition(3260,-130);

    cartel_text.loadFromFile("bloques/nivel1/cartelderecha.png");
    cartel.setTexture(cartel_text);
    cartel.setPosition(168,400);

    casa_text.loadFromFile("bloques/nivel1/casa.png");
    casa.setTexture(casa_text);
    casa.setPosition(16410,-411);

    ///Cargar a los sprites las texturas de las nubes en diferentes posiciones
    nubes_text1.loadFromFile("cielo/nivel1/nubes1.png");
    nubes1.setTexture(nubes_text1);
    nubes_text2.loadFromFile("cielo/nivel1/nubes2.png");
    nubes2.setTexture(nubes_text2);
    nubes_text3.loadFromFile("cielo/nivel1/nubes3.png");
    nubes3.setTexture(nubes_text3);

    ///Setear la posicion de nubes 1 que sería con la que empezamos el juego.
    nubes1.setPosition(0, 0);
    ///Seteamos la posicion de nubes 2 despues de nubes1 usando el largo del getGlobalBounds.
    nubes2.setPosition(nubes1.getGlobalBounds().width, 0);
    ///Seteamos la posicion de nubes 3 despues de nubes2.
    nubes3.setPosition(nubes2.getGlobalBounds().width + nubes2.getPosition().x, 0);
    nubesOffset = 0.0f;

    ///Seteo textura piso1.
    piso1.setTexture("bloques/nivel1/PASTO1.pNg");
    ///Seteo textura tierra.
    tierra.setTexture("bloques/nivel1/TIERRA.jpg");

    ///Seteo de textura de bloque flotante 1
    bloqueFlotante1.setTexture("bloques/nivel1/PASTO_FLOTANTE1.png");
    ///Seteo de textura de bloque flotante 2
    bloqueFlotante2.setTexture("bloques/nivel1/PASTO_FLOTANTE2.png");
    ///Seteo de textura de bloque flotante 3
    bloqueFlotante3.setTexture("bloques/nivel1/PASTO_FLOTANTE3.png");
    tierraFlotante.setTexture("bloques/nivel1/tierra_flotante.png");

    ///Seteo la posicion inicial de Fein.
    fein.setPosition(32,436);///32,436
    ///Seteo la posicion inicial de mi enemigo.
    enem1.setPosition(428,436);
    enem2.setPosition(916,497);
    enem3.setPosition(1450,433);
    enem4.setPosition(3218,433);
    enem5.setPosition(4356,433);
    enem6.setPosition(4760,433);
    enem8.setPosition(12398,479);
    enem9.setPosition(12730,479);
    enem10.setPosition(13002,479);
    enem11.setPosition(13254,479);
    enem12.setPosition(12142,479);

    ///Meto mi enemigo al vector de enemigos.
    enemigos.push_back(enem1);
    enemigos.push_back(enem2);
    enemigos.push_back(enem3);
    enemigos.push_back(enem4);
    enemigos.push_back(enem5);
    enemigos.push_back(enem6);
    enemigos.push_back(enem8);
    enemigos.push_back(enem9);
    enemigos.push_back(enem10);
    enemigos.push_back(enem11);
    enemigos.push_back(enem12);

    ///FUNGUS/////////////////////////
    fun1.setPosition(1008,339);
    fun2.setPosition(788,339);
    fun3.setPosition(2062,337);
    fun4.setPosition(4625,335);
    fun5.setPosition(5788,433);
    fun6.setPosition(6036,433);
    fun7.setPosition(6252,433);
    fun8.setPosition(6864,369);
    fun9.setPosition(7094,369);
    fun10.setPosition(9640,47);
    fun11.setPosition(9596,247);
    fun12.setPosition(9946,-47);
    fun13.setPosition(11746,-47);
    fun14.setPosition(11320,161);
    fun15.setPosition(11160,161);
    fun16.setPosition(12232,330);
    fun17.setPosition(12572,240);
    fun18.setPosition(13200,310);
    fun19.setPosition(12818,210);
    fun20.setPosition(14276,346);
    fun21.setPosition(17150,20);
    ///Meto mi enemigo al vector de enemigos.
    funEnemigos.push_back(fun1);
    funEnemigos.push_back(fun2);
    funEnemigos.push_back(fun3);
    funEnemigos.push_back(fun4);
    funEnemigos.push_back(fun5);
    funEnemigos.push_back(fun6);
    funEnemigos.push_back(fun7);
    funEnemigos.push_back(fun8);
    funEnemigos.push_back(fun9);
    funEnemigos.push_back(fun10);
    funEnemigos.push_back(fun11);
    funEnemigos.push_back(fun12);
    funEnemigos.push_back(fun13);
    funEnemigos.push_back(fun14);
    funEnemigos.push_back(fun15);
    funEnemigos.push_back(fun16);
    funEnemigos.push_back(fun17);
    funEnemigos.push_back(fun18);
    funEnemigos.push_back(fun19);
    funEnemigos.push_back(fun20);
    funEnemigos.push_back(fun21);

    ///FALL//////////////////////////////////
    fall1.setPosition(9068,-47);
    fall2.setPosition(16216,378);

    ///Meto mi enemigo al vector de enemigos.
    fallEnemigos.push_back(fall1);
    fallEnemigos.push_back(fall2);

    ///Obstaculo///////////////////////////
    mur1.setPosition(2545,170);
    mur2.setPosition(3150,110);
    mur3.setPosition(3150,-80);
    mur4.setPosition(5075,245);
    mur4.setMaxDistancia(100);
    mur5.setPosition(5635,355);
    mur5.setMaxDistancia(100);
    mur6.setPosition(5877,355);
    mur6.setMaxDistancia(100);
    mur7.setPosition(6120,355);
    mur7.setMaxDistancia(100);
    mur8.setPosition(7650,230);
    mur9.setPosition(7870,180);
    mur10.setPosition(10310,-240);
    mur10.setMaxDistancia(80);
    mur11.setPosition(10530,-300);
    mur11.setMaxDistancia(120);
    mur12.setPosition(10790,-300);
    mur12.setMaxDistancia(120);
    mur13.setPosition(11020,-310);
    mur13.setMaxDistancia(120);
    mur14.setPosition(11250,-320);
    mur14.setMaxDistancia(120);
    mur15.setPosition(11530,-330);
    mur15.setMaxDistancia(120);
    mur16.setPosition(11690,-270);
    mur16.setMaxDistancia(80);
    mur17.setPosition(10830,155);
    mur18.setPosition(10930,10);
    mur19.setPosition(11030,155);
    mur20.setPosition(11130,10);
    mur21.setPosition(11370,155);
    mur22.setPosition(11470,10);
    mur23.setPosition(11570,155);
    mur24.setPosition(11670,10);
    mur25.setPosition(15300,185);
    mur25.setMaxDistancia(100);

    vecobstaculos.push_back(mur1);
    vecobstaculos.push_back(mur2);
    vecobstaculos.push_back(mur3);
    vecobstaculos.push_back(mur4);
    vecobstaculos.push_back(mur5);
    vecobstaculos.push_back(mur6);
    vecobstaculos.push_back(mur7);
    vecobstaculos.push_back(mur8);
    vecobstaculos.push_back(mur9);
    vecobstaculos.push_back(mur10);
    vecobstaculos.push_back(mur11);
    vecobstaculos.push_back(mur12);
    vecobstaculos.push_back(mur13);
    vecobstaculos.push_back(mur14);
    vecobstaculos.push_back(mur15);
    vecobstaculos.push_back(mur16);
    vecobstaculos.push_back(mur17);
    vecobstaculos.push_back(mur18);
    vecobstaculos.push_back(mur19);
    vecobstaculos.push_back(mur20);
    vecobstaculos.push_back(mur21);
    vecobstaculos.push_back(mur22);
    vecobstaculos.push_back(mur23);
    vecobstaculos.push_back(mur24);
    vecobstaculos.push_back(mur25);

    ///Configuración de camara en un tamaño de 1000x600.
    view = sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1000, 600));
    ///Se aplica zoom para que se vean los pixeles y para que no parezca un juego
    ///de alta definición en graficos.
    view.zoom(0.7f);
    ///Se inicia nivel agregando las plataformas.
    initializeLevel();

    ///Inicialización del menú de pausa
    font.loadFromFile("fuente/Gamerock.otf");
    overlay.setSize(sf::Vector2f(1000, 600));
    overlay.setFillColor(sf::Color(0, 0, 0, 150));
    isPaused = false;

    ///Verificar si perdió el juego
    isGameOver = false;
    gameOverOverlay.setSize(sf::Vector2f(1000, 600));
    gameOverOverlay.setFillColor(sf::Color(0, 0, 0, 150));

    gameOverText.setFont(font);
    gameOverText.setString("Perdiste");
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);

    win = false;
    gameWinOverlay.setSize(sf::Vector2f(1000, 600));
    gameWinOverlay.setFillColor(sf::Color(0, 0, 0, 150));
    gameWinText.setFont(font);
    gameWinText.setString("GANASTE");
    gameWinText.setCharacterSize(60);
    gameWinText.setFillColor(sf::Color::White);

    backgroundMusic.openFromFile("sonidos/musica.wav");
    backgroundMusic.setLoop(true); // Repetir la música en bucle
    backgroundMusic.setVolume(20.0f);

    killSound.loadFromFile("sonidos/kill.wav");
    kill.setBuffer(killSound);

    keyBuffer.loadFromFile("sonidos/key.wav");
    key.setBuffer(keyBuffer);

    winBuffer.loadFromFile("sonidos/win.wav");
    wins.setBuffer(winBuffer);

    puerta_text.loadFromFile("bloques/nivel1/puerta.png");
    puerta.setTexture(puerta_text);
    puerta.setPosition(8600,-110);

    llaveCasa1.loadFromFile("llave/llavePuerta.png");
    llaveCasa1_sprite.setTexture(llaveCasa1);
    llaveCasa1_sprite.setPosition(11710,-280);

    llaveCasa2.loadFromFile("llave/llavePuerta.png");
    llaveCasa2_sprite.setTexture(llaveCasa2);
    llaveCasa2_sprite.setPosition(11230,80);

    llaveCasa3.loadFromFile("llave/llavePuerta.png");
    llaveCasa3_sprite.setTexture(llaveCasa3);
    llaveCasa3_sprite.setPosition(17920,-305);

    killSound.loadFromFile("sonidos/kill.wav");
    kill.setBuffer(killSound);

    sonidoVida.loadFromFile("sonidos/invencible1.wav");
    vida.setBuffer(sonidoVida);
    vida.setVolume(20.0f);

    gameOverBuffer.loadFromFile("sonidos/gameover.wav");
    gameOver.setBuffer(gameOverBuffer);

    cartelLlave_text.loadFromFile("bloques/nivel1/cartelllave.png");
    cartelLlave.setTexture(cartelLlave_text);

    cartelLlave2_text.loadFromFile("bloques/nivel1/cartelllave.png");
    cartelLlave2.setTexture(cartelLlave2_text);

    cartelLlave3_text.loadFromFile("bloques/nivel1/cartelllave.png");
    cartelLlave3.setTexture(cartelLlave3_text);

    cartelLlave4_text.loadFromFile("bloques/nivel1/cartelllave.png");
    cartelLlave4.setTexture(cartelLlave4_text);

    cartelLlave.setPosition(3238,270);
    cartelLlave2.setPosition(9952,-80);
    cartelLlave3.setPosition(9952,305);
    cartelLlave4.setPosition(17325,-95);

    cartelArriba_text.loadFromFile("bloques/nivel1/cartelarriba.png");
    cartelArriba.setTexture(cartelArriba_text);
    cartelArriba.setPosition(16996,345);

arbusto1.loadFromFile("bloques/nivel1/arbusto.png");
arbusto_1.setTexture(arbusto1);

arbusto2.loadFromFile("bloques/nivel1/arbusto_g.png");
arbusto_2.setTexture(arbusto2);
arbusto_2.setPosition(4146,398);

cartel_home.loadFromFile("bloques/nivel1/cartel_home.png");
cartel_h.setTexture(cartel_home);

piedra_g.loadFromFile("bloques/nivel1/piedra_dos.png");
_piedra_g.setTexture(piedra_g);
_piedra_g2.setTexture(piedra_g);
_piedra_g.setPosition(4716,415);
_piedra_g2.setPosition(9588,30);

piedra_sapo.loadFromFile("bloques/nivel1/piedra_sapo.png");
_piedra_sapo.setTexture(piedra_sapo);
_piedra_sapo.setPosition(1616,397);

piedra_sapo_1.loadFromFile("bloques/nivel1/piedra_sapo_f.png");
_piedra_sapo_1.setTexture(piedra_sapo_1);
_piedra_sapo_1.setPosition(16790,-330);

farola.loadFromFile("bloques/nivel1/farola.png");
_farola.setTexture(farola);
_farola.setPosition(8100,-130);
_farola2.setTexture(farola);
_farola2.setPosition(4932,287);
_farola3.setTexture(farola);
_farola3.setPosition(528,350);
_farola4.setTexture(farola);
_farola4.setPosition(15694,297);
}

void Nivel::handleGameWin(sf::RenderWindow &window) {
    window.draw(gameWinOverlay);
    window.draw(gameWinText);
    window.display();
}

void Nivel::handleGameOver(sf::RenderWindow &window) {
    window.draw(gameOverOverlay);
    window.draw(gameOverText);
    window.display();
}

void Nivel::showPauseMenu(sf::RenderWindow &window) {
    // Renderizar el fondo oscurecido
    window.draw(overlay);

    // Renderizar el texto de pausa
    sf::Text pauseText;
    pauseText.setFont(font);
    pauseText.setString("| |");
    pauseText.setCharacterSize(60);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setStyle(sf::Text::Bold);
    pauseText.setPosition(window.getView().getCenter().x - pauseText.getGlobalBounds().width / 2,
                          window.getView().getCenter().y - pauseText.getGlobalBounds().height / 2);
    window.draw(pauseText);

    window.display();
}

void Nivel::handlePauseMenuInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
}


void Nivel::processEvents(sf::RenderWindow &window) {
    ///Manejo de eventos
    ///Crea un evento
    sf::Event event;
    ///Despues lo procesa como en el main
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (!isGameOver) { // No permitir pausar si el juego ha terminado
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                isPaused = !isPaused;
            }
        }

        if (isGameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            // Volver al menú principal al presionar Enter
            // Aquí puedes añadir la lógica para volver al menú principal
        }
    }

    if (isPaused) {
        handlePauseMenuInput(window);
    }
}

void Nivel::update(sf::RenderWindow &window) {
    if (isGameOver) {
        handleGameOver(window); // Manejar la pantalla de Game Over
        return;
    }

    ///Actualiza el estado del piso.
    piso1.update();
    ///Actualiza al heroe con las plataformas.
    fein.update(platforms);
    ///Actualiza el estado del heroe con la llave
    if(fein.heckKeyCollision(llave)){
     llave.setPosition(0,0);
     key.play();
    }

    if (fein.getHasKey() && fein.getHitBox().intersects(puerta.getGlobalBounds())) {
         puerta.setPosition(0,0);
    }

    if(fein.getHitBox().intersects(llaveCasa1_sprite.getGlobalBounds())){
        llaveCasa1_sprite.setPosition(0,0);
        fein.setLlaves();
        key.play();
    }

    if(fein.getHitBox().intersects(llaveCasa2_sprite.getGlobalBounds())){
        llaveCasa2_sprite.setPosition(0,0);
        fein.setLlaves();
        key.play();
    }

    if(fein.getHitBox().intersects(llaveCasa3_sprite.getGlobalBounds())){
        llaveCasa3_sprite.setPosition(0,0);
        fein.setLlaves();
        key.play();
    }

    if(fein.getHitBox().intersects(casa.getGlobalBounds()) && fein.getHasKeys() == 3){
        win = true;
    }

    if (win) {
        handleGameWin(window);
        return; // Salir del método de update para no seguir actualizando
    }

    ///Actualizar la posición de las nubes
    float parallaxSpeed = 0.2f;
    sf::Vector2f viewCenter = view.getCenter();

    /// Mover las nubes1 a la izquierda
    nubes1.move(-parallaxSpeed, 0);
    /// Mover las nubes2 a la izquierda
    nubes2.move(-parallaxSpeed, 0);
    /// Mover las nubes3 a la izquierda
    nubes3.move(-parallaxSpeed, 0);

    /// Si las nubes1 salen de la pantalla, reposicionarlas a la derecha de nubes3
    if (nubes1.getPosition().x + nubes1.getGlobalBounds().width < viewCenter.x - view.getSize().x / 2) {
        nubes1.setPosition(nubes3.getPosition().x + nubes3.getGlobalBounds().width, 0);
    }

    /// Si las nubes2 salen de la pantalla, reposicionarlas a la derecha de nubes1
    if (nubes2.getPosition().x + nubes2.getGlobalBounds().width < viewCenter.x - view.getSize().x / 2) {
        nubes2.setPosition(nubes1.getPosition().x + nubes1.getGlobalBounds().width, 0);
    }

    /// Si las nubes3 salen de la pantalla, reposicionarlas a la derecha de nubes2
    if (nubes3.getPosition().x + nubes3.getGlobalBounds().width < viewCenter.x - view.getSize().x / 2) {
        nubes3.setPosition(nubes2.getPosition().x + nubes2.getGlobalBounds().width, 0);
    }

    /// Actualizar la posición del fondo.
    cielo.setPosition(viewCenter.x - cielo.getGlobalBounds().width / 2, viewCenter.y - cielo.getGlobalBounds().height / 2);

    /// Actualizar la vista del jugador dejando a fein en el centro de todo.
    /// Y también la barra de vida.

    view.setCenter(sf::Vector2f(fein.getPositionx() + fein.getglobalboundswidth() / 2.0f, fein.getPositiony()+10 + fein.getglobalboundsheight() *-2));

     if(fein.getPositiony()>=630){
        fein.setHealth(0);
        view.setCenter(sf::Vector2f(fein.getPositionx()+fein.getglobalboundswidth()/2.0f,383));
        isGameOver=true;
     }

    window.setView(view);
    fein.updateHealthBarPosition(view);

    //////////////////CILI//////////////////////
    /// For que itera el vector de enemigos y hace que cada enemigo haga su funcion update para
    /// detectar colisiones o hacerle daño a Fein.
    for (auto& enemigo : enemigos) {
    enemigo.update(platforms, fein.getPosition());

    bool Pisado = false;

    sf::FloatRect heroeBounds = fein.getLimites();
    sf::FloatRect enemyBounds = enemigo.getLimite();

    // Verifica si pisa al enemigo
    if (fein.getCayendo() && fein.getInferior() >= enemigo.getSuperior() && heroeBounds.intersects(enemyBounds)) {
        fein.setVelocityY(-7);
        Pisado = true;
        kill.play();
        // Eliminar al enemigo en el vector
        int cant=enemigos.size();
        for (int i = 0; i < cant; ++i) {
        if (&enemigos[i] == &enemigo) {
            enemigos.erase(enemigos.begin() + i);
            break;
        }
    }

    } else if (!Pisado && heroeBounds.intersects(enemyBounds) && fein.getOnGround()) {

        // Le hace daño a fein
        fein.takeDamage(1);
        if (vida.getStatus() != sf::Sound::Playing && fein.getIsInvulnerable()) { // Evitar reproducir múltiples veces simultáneamente
            vida.play();
        }
    }
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////
    ////////////////////FUNGUS////////////////////
for (auto& enemigo_ : funEnemigos) {
    enemigo_.update(platforms);

    bool Pisado = false;

    sf::FloatRect heroeBounds = fein.getLimites();
    sf::FloatRect enemyBounds = enemigo_.getLimite();

    // Verifica si pisa al enemigo
    if (fein.getCayendo() && fein.getInferior() >= enemigo_.getSuperior() && heroeBounds.intersects(enemyBounds)) {
        fein.setVelocityY(-7);
        Pisado = true;
        kill.play();
        // Eliminar al enemigo en el vector
        /*int cant=funEnemigos.size();
        for (int i = 0; i < cant; ++i) {
        if (&funEnemigos[i] == &enemigo_) {
            funEnemigos.erase(funEnemigos.begin() + i);
            break;
        }
    }*/

    } else if (!Pisado && heroeBounds.intersects(enemyBounds) && fein.getOnGround()) {

        // Le hace daño a fein
        fein.takeDamage(1);
        if (vida.getStatus() != sf::Sound::Playing && fein.getIsInvulnerable()) { // Evitar reproducir múltiples veces simultáneamente
                    vida.play();
        }
    }
}


for (auto& enemigoF : fallEnemigos) {
    enemigoF.update(platforms, fein.getPosition());

    bool Pisado = false;

    sf::FloatRect heroeBounds = fein.getLimites();
    sf::FloatRect enemyBounds = enemigoF.getLimite();

    // Verifica si pisa al enemigo
    if (fein.getCayendo() && fein.getInferior() >= enemigoF.getSuperior() && heroeBounds.intersects(enemyBounds)) {
        fein.setVelocityY(-7);
        Pisado = true;



        }else if (!Pisado && heroeBounds.intersects(enemyBounds) && fein.getOnGround()) {

        // Le hace daño a fein
        fein.takeDamage(1);
        if (vida.getStatus() != sf::Sound::Playing && fein.getIsInvulnerable()) { // Evitar reproducir múltiples veces simultáneamente
                    vida.play();
        }
    }


    }

for (auto& obss : vecobstaculos) {
    obss.update(platforms);

    sf::FloatRect heroeBounds = fein.getLimites();
    sf::FloatRect enemyBounds = obss.getLimite();

    if(heroeBounds.intersects(enemyBounds)){
        fein.takeDamage(1);
        if (vida.getStatus() != sf::Sound::Playing && fein.getIsInvulnerable()) { // Evitar reproducir múltiples veces simultáneamente
                    vida.play();
        }
    }

}

 if (fein.getHealth() <= 0) {
                isGameOver = true; // Si la vida es 0, el juego termina
            }
}

bool Nivel::run(sf::RenderWindow &window, bool returnMenu) {
    bool volver=false;
    backgroundMusic.play();
    ///While principal del juego.
    while (window.isOpen()) {
        ///Llama a funciones de Nivel
        processEvents(window);
        if (!isPaused) {
            update(window);
        }
        volver=render(window);
        if( volver==true ){
            return true;

        }
    }
return false;
}

void Nivel::initializeLevel() {
    ///Configurar posiciones y hitboxes de las plataformas
    for (int i = 0; i < 20; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 436);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    bloqueFlotante1.setPosition(630,339);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(660,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(690,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(720,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(750,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(780,339);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(990,339);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(1020,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(1050,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(1080,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(1110,339);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(1140,339);
    platforms.push_back(bloqueFlotante3.getHitBox());

    for (int i = 20; i < 40; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 497);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 625);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 657);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 40; i < 60; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    bloqueFlotante1.setPosition(1910,337);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(1940,337);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(1970,337);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(2000,337);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(2030,337);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(2060,337);
    platforms.push_back(bloqueFlotante3.getHitBox());


    bloqueFlotante1.setPosition(2270,306);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(2300,306);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(2330,306);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(2360,306);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(2390,306);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(2660,306);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(2690,306);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(2720,306);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(2750,306);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(2930,404);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante3.setPosition(2960,404);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(3200,300);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(3230,300);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(3260,300);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(3020,200);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(3050,200);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(3080,200);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(3200,100);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(3230,100);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(3260,100);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(3020,0);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(3050,0);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(3080,0);
    platforms.push_back(bloqueFlotante3.getHitBox());

    bloqueFlotante1.setPosition(3200,-100);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(3230,-100);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(3260,-100);
    platforms.push_back(bloqueFlotante3.getHitBox());

    for (int i = 104; i < 115; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }
    piso1.setPosition(3450, 337);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(3450, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3450, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(3650, 305);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(3650, 337);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3650, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(3820, 273);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(3820, 305);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 337);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(3820, 593);
        platforms.push_back(tierra.getHitBox());

    for (int i = 135; i < 160; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    bloqueFlotante1.setPosition(4501,335);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(4531,335);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(4561,335);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante2.setPosition(4591,335);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(4621,335);
    platforms.push_back(bloqueFlotante3.getHitBox());

    for (int i = 160; i < 163; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 401);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 163; i < 166; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 369);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 173; i < 176; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 369);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 176; i < 179; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 401);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 433);
        platforms.push_back(tierra.getHitBox());;
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 179; i < 186; i++) {
        int cant = i * 30;
         piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 190; i < 194; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 198; i < 202; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    for (int i = 206; i < 210; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
    }

    bloqueFlotante1.setPosition(6400,335);
    platforms.push_back(bloqueFlotante1.getHitBox());
    bloqueFlotante2.setPosition(6430,335);
    platforms.push_back(bloqueFlotante2.getHitBox());
    bloqueFlotante3.setPosition(6460,335);
    platforms.push_back(bloqueFlotante3.getHitBox());

        piso1.setPosition(6660, 401);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(6660, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6660, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6660, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6660, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6660, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6660, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(6690, 369);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(6690, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6690, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(6720, 337);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(6720, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(6720, 593);
        platforms.push_back(tierra.getHitBox());

        bloqueFlotante1.setPosition(6800, 369);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(6830, 369);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(6860, 369);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(6890, 369);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(7030, 369);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(7060, 369);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(7090, 369);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(7120, 369);
        platforms.push_back(bloqueFlotante3.getHitBox());

        for (int i = 225; i < 240; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 465);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
        }

        piso1.setPosition(7200, 337);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(7200, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7200, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(7230, 369);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(7230, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7230, 593);
        platforms.push_back(tierra.getHitBox());

        piso1.setPosition(7260, 401);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(7260, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7260, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7260, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7260, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7260, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(7260, 593);
        platforms.push_back(tierra.getHitBox());

        bloqueFlotante1.setPosition(7500, 369);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(7530, 369);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(7750, 305);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(7780, 305);
        platforms.push_back(bloqueFlotante3.getHitBox());

        for (int i = 268; i < 310; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, -47);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, -15);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 17);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 49);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 81);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 113);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 145);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 177);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 209);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 241);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 273);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 305);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 337);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 369);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 401);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 433);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 465);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 497);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 529);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 561);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 593);
        platforms.push_back(tierra.getHitBox());
        }

        bloqueFlotante1.setPosition(7950, 273);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(7980, 273);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(8010, 273);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante1.setPosition(8010, 177);
        platforms.push_back(bloqueFlotante1.getHitBox());

        bloqueFlotante1.setPosition(7850, 95);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(7880, 95);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(8010, 2);
        platforms.push_back(bloqueFlotante1.getHitBox());

        bloqueFlotante1.setPosition(9420, -47);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9450, -47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9480, -47);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9720, -47);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9750, -47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9780, -47);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9540, 47);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9570, 47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(9600, 47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(9630, 47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9660, 47);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9420, 147);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9450, 147);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9480, 147);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9720, 147);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9750, 147);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9780, 147);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9540, 247);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9570, 247);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(9600, 247);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(9630, 247);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9660, 247);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9420, 347);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9450, 347);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9480, 347);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9720, 347);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(9750, 347);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(9780, 347);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9930, -47);
        platforms.push_back(bloqueFlotante1.getHitBox());
        for (int i = 332; i < 391; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, -47);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }
        bloqueFlotante3.setPosition(11730, -47);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(9930, 347);
        platforms.push_back(bloqueFlotante1.getHitBox());
        for (int i = 332; i < 390; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 347);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }
        bloqueFlotante2.setPosition(11700, 347);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante1.setPosition(10150, -540);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(10180, -540);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(10210, -540);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante2.setPosition(10190, -145);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(10390, -190);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(10650, -190);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(10890, -210);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(11100, -230);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(11370, -240);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante1.setPosition(11630, -240);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(11660, -240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(11690, -240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(11720, -240);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(10200, 250);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(10230, 250);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(10000, 190);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(10030, 190);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(10060, 190);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(10310, 140);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(10340, 140);
        platforms.push_back(bloqueFlotante3.getHitBox());

        tierra.setPosition(10620,321);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(10620,289);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(10620,257);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(10620,225);
        platforms.push_back(tierra.getHitBox());
        piso1.setPosition(10620,193);
        platforms.push_back(piso1.getHitBox());

        bloqueFlotante3.setPosition(10650, 257);
        platforms.push_back(bloqueFlotante3.getHitBox());
        for (int i = 359; i < 373; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 161);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 193);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 225);
        platforms.push_back(tierra.getHitBox());
        bloqueFlotante2.setPosition(cant, 250);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }

        for (int i = 377; i < 391; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 161);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 193);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 225);
        platforms.push_back(tierra.getHitBox());
        bloqueFlotante2.setPosition(cant, 250);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }

        for (int i = 401; i < 444; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 479);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 511);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 543);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 575);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 607);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 639);
        platforms.push_back(tierra.getHitBox());
        }

        bloqueFlotante1.setPosition(11840, 397);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(11870, 397);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(11900, 397);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(11930, 397);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(13420, 346);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(13450, 346);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(13480, 346);
        platforms.push_back(bloqueFlotante3.getHitBox());

        for (int i = 458; i < 481; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 346);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 378);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 410);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 442);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 474);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 506);
        platforms.push_back(tierra.getHitBox());
        }

        for (int i = 481; i < 488; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 378);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, 410);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 442);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 474);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 506);
        platforms.push_back(tierra.getHitBox());
        }

        for (int i = 460; i < 478; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        platforms.push_back(bloqueFlotante2.getHitBox());
        tierra.setPosition(cant,230);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 198);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 198);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 166);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 166);
        platforms.push_back(tierra.getHitBox());
        }


        bloqueFlotante1.setPosition(14460, 250);
        platforms.push_back(bloqueFlotante1.getHitBox());
        for (int i = 483; i < 487; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }
        bloqueFlotante3.setPosition(14610, 250);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(14900, 346);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(14930, 346);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante2.setPosition(15155, 332);
        platforms.push_back(bloqueFlotante2.getHitBox());
        piso1.setPosition(15155, 290);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(15155, 320);
        platforms.push_back(tierra.getHitBox());

        bloqueFlotante2.setPosition(15400, 332);
        platforms.push_back(bloqueFlotante2.getHitBox());
        piso1.setPosition(15400, 290);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(15400, 320);
        platforms.push_back(tierra.getHitBox());

        for (int i = 520; i < 580; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 378);
        platforms.push_back(bloqueFlotante2.getHitBox());
        }

        for (int i = 540; i < 565; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 243);
        platforms.push_back(bloqueFlotante2.getHitBox());
        piso1.setPosition(cant, -294);
        platforms.push_back(piso1.getHitBox());
        tierra.setPosition(cant, -262);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -230);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -198);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -166);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -134);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -102);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -70);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -38);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, -6);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 26);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 58);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 90);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 122);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 154);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 186);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(cant, 218);
        platforms.push_back(tierra.getHitBox());
        }

        bloqueFlotante1.setPosition(17070, 320);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(17100, 320);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(17130, 320);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante2.setPosition(17250, 270);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(17070, 200);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante3.setPosition(16950, 100);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(17070, 20);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(17100, 20);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(17130, 20);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(17160, 20);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(17190, 20);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante2.setPosition(17320, -60);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(17320, -60);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(17130, -120);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante3.setPosition(16950, -200);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante2.setPosition(3910, 370);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(17540, -130);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante2.setPosition(17690, -230);
        platforms.push_back(bloqueFlotante2.getHitBox());

        bloqueFlotante1.setPosition(17890, -265);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(17920, -265);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(17950, -265);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(12110, 330);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(12140, 330);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12170, 330);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12200, 330);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(12230, 330);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(12430, 240);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(12460, 240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12490, 240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12520, 240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(12550, 240);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(12830, 390);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante3.setPosition(12860, 390);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(12740, 210);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(12770, 210);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12800, 210);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(12830, 210);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(12860, 210);
        platforms.push_back(bloqueFlotante3.getHitBox());

        bloqueFlotante1.setPosition(13100, 310);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(13130, 310);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(13160, 310);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(13190, 310);
        platforms.push_back(bloqueFlotante3.getHitBox());

        tierra.setPosition(11700,322);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(11700,290);
        platforms.push_back(tierra.getHitBox());
        tierra.setPosition(11700,258);
        platforms.push_back(tierra.getHitBox());

        bloqueFlotante1.setPosition(11840,240);
        platforms.push_back(bloqueFlotante1.getHitBox());
        bloqueFlotante2.setPosition(11870, 240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante2.setPosition(11900, 240);
        platforms.push_back(bloqueFlotante2.getHitBox());
        bloqueFlotante3.setPosition(11930, 240);
        platforms.push_back(bloqueFlotante3.getHitBox());
}

////////////////////////s//////////////////////////////

bool Nivel::render(sf::RenderWindow &window) {
    ///Limpia todo lo que haya en la ventana.
    window.clear();
    ///Dibuja el cielo.
    window.draw(cielo);
    ///Dibuja nubes1 en la posicion de nubes1.
    window.draw(nubes1);
    ///Dibuja nubes2 en la posicion de nubes2.
    window.draw(nubes2);
    ///Dibuja nubes3 en la posicion de nubes3.
    window.draw(nubes3);
    window.draw(cartel);
    window.draw(casa);
    window.draw(puerta);
    window.draw(llave);
    window.draw(cartelLlave);
    window.draw(cartelLlave2);
    window.draw(cartelLlave3);
    window.draw(cartelLlave4);
    window.draw(cartelArriba);

    window.draw(_farola);
    window.draw(_farola2);
    window.draw(_farola3);
    window.draw(_farola4);

    window.draw(_piedra_sapo);
    window.draw(arbusto_2);
    window.draw(_piedra_g);
    window.draw(_piedra_g2);

    window.draw(_piedra_sapo_1);

    ///For para dibujar los bloques.
    for (int i = -40; i < 20; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    bloqueFlotante1.setPosition(630,337);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(660,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(690,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(720,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(750,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(780,337);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(990,337);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(1020,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(1050,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(1080,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(1110,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(1140,337);
    window.draw(bloqueFlotante3);

    for (int i = 20; i < 40; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 497);
        window.draw(piso1);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
        tierra.setPosition(cant, 625);
        window.draw(tierra);
        tierra.setPosition(cant, 657);
        window.draw(tierra);
    }

    for (int i = 40; i < 60; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    bloqueFlotante1.setPosition(1910,337);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(1940,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(1970,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(2000,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(2030,337);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(2060,337);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(2270,306);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(2300,306);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(2330,306);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(2360,306);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(2390,306);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(2660,306);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(2690,306);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(2720,306);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(2750,306);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(2930,404);
    window.draw(bloqueFlotante1);
    bloqueFlotante3.setPosition(2960,404);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(2930,404);
    window.draw(bloqueFlotante1);
    bloqueFlotante3.setPosition(2960,404);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(3200,300);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(3230,300);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(3260,300);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(3020,200);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(3050,200);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(3080,200);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(3200,100);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(3230,100);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(3260,100);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(3020,0);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(3050,0);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(3080,0);
    window.draw(bloqueFlotante3);

    bloqueFlotante1.setPosition(3200,-100);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(3230,-100);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(3260,-100);
    window.draw(bloqueFlotante3);

    for (int i = 104; i < 115; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

        piso1.setPosition(3450, 337);
        window.draw(piso1);
        tierra.setPosition(3450, 369);
        window.draw(tierra);
        tierra.setPosition(3450, 401);
        window.draw(tierra);
        tierra.setPosition(3450, 433);
        window.draw(tierra);
        tierra.setPosition(3450, 465);
        window.draw(tierra);
        tierra.setPosition(3450, 497);
        window.draw(tierra);
        tierra.setPosition(3450, 529);
        window.draw(tierra);
        tierra.setPosition(3450, 561);
        window.draw(tierra);
        tierra.setPosition(3450, 593);
        window.draw(tierra);

        piso1.setPosition(3650, 305);
        window.draw(piso1);
        tierra.setPosition(3650, 337);
        window.draw(tierra);
        tierra.setPosition(3650, 369);
        window.draw(tierra);
        tierra.setPosition(3650, 401);
        window.draw(tierra);
        tierra.setPosition(3650, 433);
        window.draw(tierra);
        tierra.setPosition(3650, 465);
        window.draw(tierra);
        tierra.setPosition(3650, 497);
        window.draw(tierra);
        tierra.setPosition(3650, 529);
        window.draw(tierra);
        tierra.setPosition(3650, 561);
        window.draw(tierra);
        tierra.setPosition(3650, 593);
        window.draw(tierra);

        piso1.setPosition(3820, 273);
        window.draw(piso1);
        tierra.setPosition(3820, 305);
        window.draw(tierra);
        tierra.setPosition(3820, 337);
        window.draw(tierra);
        tierra.setPosition(3820, 369);
        window.draw(tierra);
        tierra.setPosition(3820, 401);
        window.draw(tierra);
        tierra.setPosition(3820, 433);
        window.draw(tierra);
        tierra.setPosition(3820, 465);
        window.draw(tierra);
        tierra.setPosition(3820, 497);
        window.draw(tierra);
        tierra.setPosition(3820, 529);
        window.draw(tierra);
        tierra.setPosition(3820, 561);
        window.draw(tierra);
        tierra.setPosition(3820, 593);
        window.draw(tierra);

    for (int i = 135; i < 160; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    bloqueFlotante1.setPosition(4501,335);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(4531,335);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(4561,335);
    window.draw(bloqueFlotante2);
    bloqueFlotante2.setPosition(4591,335);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(4621,335);
    window.draw(bloqueFlotante3);

    for (int i = 160; i < 163; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 401);
        window.draw(piso1);
        tierra.setPosition(cant, 433);
        window.draw(tierra);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 163; i < 166; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 369);
        window.draw(piso1);
        tierra.setPosition(cant, 401);
        window.draw(tierra);
        tierra.setPosition(cant, 433);
        window.draw(tierra);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 173; i < 176; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 369);
        window.draw(piso1);
        tierra.setPosition(cant, 401);
        window.draw(tierra);
        tierra.setPosition(cant, 433);
        window.draw(tierra);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 176; i < 179; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 401);
        window.draw(piso1);
        tierra.setPosition(cant, 433);
        window.draw(tierra);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }
    /**/
    for (int i = 179; i < 186; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 190; i < 194; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 198; i < 202; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    for (int i = 206; i < 210; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 433);
        window.draw(piso1);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
    }

    bloqueFlotante1.setPosition(6400,335);
    window.draw(bloqueFlotante1);
    bloqueFlotante2.setPosition(6430,335);
    window.draw(bloqueFlotante2);
    bloqueFlotante3.setPosition(6460,335);
    window.draw(bloqueFlotante3);


        piso1.setPosition(6660, 401);
        window.draw(piso1);
        tierra.setPosition(6660, 433);
        window.draw(tierra);
        tierra.setPosition(6660, 465);
        window.draw(tierra);
        tierra.setPosition(6660, 497);
        window.draw(tierra);
        tierra.setPosition(6660, 529);
        window.draw(tierra);
        tierra.setPosition(6660, 561);
        window.draw(tierra);
        tierra.setPosition(6660, 593);
        window.draw(tierra);

        piso1.setPosition(6690, 369);
        window.draw(piso1);
        tierra.setPosition(6690, 401);
        window.draw(tierra);
        tierra.setPosition(6690, 433);
        window.draw(tierra);
        tierra.setPosition(6690, 465);
        window.draw(tierra);
        tierra.setPosition(6690, 497);
        window.draw(tierra);
        tierra.setPosition(6690, 529);
        window.draw(tierra);
        tierra.setPosition(6690, 561);
        window.draw(tierra);
        tierra.setPosition(6690, 593);
        window.draw(tierra);

        piso1.setPosition(6720, 337);
        window.draw(piso1);
        tierra.setPosition(6720, 369);
        window.draw(tierra);
        tierra.setPosition(6720, 401);
        window.draw(tierra);
        tierra.setPosition(6720, 433);
        window.draw(tierra);
        tierra.setPosition(6720, 465);
        window.draw(tierra);
        tierra.setPosition(6720, 497);
        window.draw(tierra);
        tierra.setPosition(6720, 529);
        window.draw(tierra);
        tierra.setPosition(6720, 561);
        window.draw(tierra);
        tierra.setPosition(6720, 593);
        window.draw(tierra);

        bloqueFlotante1.setPosition(6800, 369);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(6830, 369);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(6860, 369);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(6890, 369);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(7030, 369);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(7060, 369);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(7090, 369);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(7120, 369);
        window.draw(bloqueFlotante3);

        for (int i = 225; i < 240; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 465);
        window.draw(piso1);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
        }
        piso1.setPosition(7200, 337);
        window.draw(piso1);
        tierra.setPosition(7200, 369);
        window.draw(tierra);
        tierra.setPosition(7200, 401);
        window.draw(tierra);
        tierra.setPosition(7200, 433);
        window.draw(tierra);
        tierra.setPosition(7200, 465);
        window.draw(tierra);
        tierra.setPosition(7200, 497);
        window.draw(tierra);
        tierra.setPosition(7200, 529);
        window.draw(tierra);
        tierra.setPosition(7200, 561);
        window.draw(tierra);
        tierra.setPosition(7200, 593);
        window.draw(tierra);

        piso1.setPosition(7230, 369);
        window.draw(piso1);
        tierra.setPosition(7230, 401);
        window.draw(tierra);
        tierra.setPosition(7230, 433);
        window.draw(tierra);
        tierra.setPosition(7230, 465);
        window.draw(tierra);
        tierra.setPosition(7230, 497);
        window.draw(tierra);
        tierra.setPosition(7230, 529);
        window.draw(tierra);
        tierra.setPosition(7230, 561);
        window.draw(tierra);
        tierra.setPosition(7230, 593);
        window.draw(tierra);

        piso1.setPosition(7260, 401);
        window.draw(piso1);
        tierra.setPosition(7260, 433);
        window.draw(tierra);
        tierra.setPosition(7260, 465);
        window.draw(tierra);
        tierra.setPosition(7260, 497);
        window.draw(tierra);
        tierra.setPosition(7260, 529);
        window.draw(tierra);
        tierra.setPosition(7260, 561);
        window.draw(tierra);
        tierra.setPosition(7260, 593);
        window.draw(tierra);

        bloqueFlotante1.setPosition(7500, 369);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(7530, 369);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(7750, 305);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(7780, 305);
        window.draw(bloqueFlotante3);

        for (int i = 268; i < 310; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, -47);
        window.draw(piso1);
        tierra.setPosition(cant, -15);
        window.draw(tierra);
        tierra.setPosition(cant, 17);
        window.draw(tierra);
        tierra.setPosition(cant, 49);
        window.draw(tierra);
        tierra.setPosition(cant, 81);
        window.draw(tierra);
        tierra.setPosition(cant, 113);
        window.draw(tierra);
        tierra.setPosition(cant, 145);
        window.draw(tierra);
        tierra.setPosition(cant, 177);
        window.draw(tierra);
        tierra.setPosition(cant, 209);
        window.draw(tierra);
        tierra.setPosition(cant, 241);
        window.draw(tierra);
        tierra.setPosition(cant, 273);
        window.draw(tierra);
        tierra.setPosition(cant, 305);
        window.draw(tierra);
        tierra.setPosition(cant, 337);
        window.draw(tierra);
        tierra.setPosition(cant, 369);
        window.draw(tierra);
        tierra.setPosition(cant, 401);
        window.draw(tierra);
        tierra.setPosition(cant, 433);
        window.draw(tierra);
        tierra.setPosition(cant, 465);
        window.draw(tierra);
        tierra.setPosition(cant, 497);
        window.draw(tierra);
        tierra.setPosition(cant, 529);
        window.draw(tierra);
        tierra.setPosition(cant, 561);
        window.draw(tierra);
        tierra.setPosition(cant, 593);
        window.draw(tierra);
        }

        bloqueFlotante1.setPosition(7950, 273);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(7980, 273);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(8010, 273);
        window.draw(bloqueFlotante2);

        bloqueFlotante1.setPosition(8010, 177);
        window.draw(bloqueFlotante1);

        bloqueFlotante1.setPosition(7850, 95);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(7880, 95);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(8010, 2);
        window.draw(bloqueFlotante1);

        bloqueFlotante1.setPosition(9420, -47);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9450, -47);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9480, -47);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9720, -47);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9750, -47);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9780, -47);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9540, 47);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9570, 47);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(9600, 47);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(9630, 47);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9660, 47);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9420, 147);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9450, 147);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9480, 147);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9720, 147);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9750, 147);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9780, 147);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9540, 247);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9570, 247);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(9600, 247);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(9630, 247);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9660, 247);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9420, 347);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9450, 347);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9480, 347);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9720, 347);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(9750, 347);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(9780, 347);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9930, -47);
        window.draw(bloqueFlotante1);
        for (int i = 332; i < 391; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, -47);
        window.draw(bloqueFlotante2);
        }
        bloqueFlotante3.setPosition(11730, -47);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(9930, 347);
        window.draw(bloqueFlotante1);
        for (int i = 332; i < 390; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 347);
        window.draw(bloqueFlotante2);
        }
        bloqueFlotante2.setPosition(11700, 347);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(10190, -145);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(10390, -190);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(10650, -190);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(10890, -210);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(11100, -230);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(11380, -240);
        window.draw(bloqueFlotante2);

        bloqueFlotante1.setPosition(11630, -240);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(11660, -240);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(11690, -240);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(11720, -240);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(10200, 250);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(10230, 250);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(10000, 190);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(10030, 190);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(10060, 190);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(10310, 140);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(10340, 140);
        window.draw(bloqueFlotante3);

        tierra.setPosition(10620,321);
        window.draw(tierra);
        tierra.setPosition(10620,289);
        window.draw(tierra);
        tierra.setPosition(10620,257);
        window.draw(tierra);
        tierra.setPosition(10620,225);
        window.draw(tierra);
        piso1.setPosition(10620,193);
        window.draw(piso1);

        bloqueFlotante3.setPosition(10650, 257);
        window.draw(bloqueFlotante3);

        for (int i = 359; i < 373; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        window.draw(bloqueFlotante2);
        piso1.setPosition(cant, 161);
        window.draw(piso1);
        tierra.setPosition(cant, 193);
        window.draw(tierra);
        tierra.setPosition(cant, 225);
        window.draw(tierra);
        }

        for (int i = 377; i < 391; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        window.draw(bloqueFlotante2);
        piso1.setPosition(cant, 161);
        window.draw(piso1);
        tierra.setPosition(cant, 193);
        window.draw(tierra);
        tierra.setPosition(cant, 225);
        window.draw(tierra);
        }

        for (int i = 401; i < 444; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 479);
        window.draw(piso1);
        tierra.setPosition(cant, 511);
        window.draw(tierra);
        tierra.setPosition(cant, 543);
        window.draw(tierra);
        tierra.setPosition(cant, 575);
        window.draw(tierra);
        tierra.setPosition(cant, 607);
        window.draw(tierra);
        tierra.setPosition(cant, 639);
        window.draw(tierra);
        }

        bloqueFlotante1.setPosition(11840, 397);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(11870, 397);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(11900, 397);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(11930, 397);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(13420, 346);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(13450, 346);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(13480, 346);
        window.draw(bloqueFlotante3);

        for (int i = 458; i < 481; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 346);
        window.draw(piso1);
        tierra.setPosition(cant, 378);
        window.draw(tierra);
        tierra.setPosition(cant, 410);
        window.draw(tierra);
        tierra.setPosition(cant, 442);
        window.draw(tierra);
        tierra.setPosition(cant, 474);
        window.draw(tierra);
        tierra.setPosition(cant, 506);
        window.draw(tierra);
        }

        for (int i = 481; i < 488; i++) {
        int cant = i * 30;
        piso1.setPosition(cant, 378);
        window.draw(piso1);
        tierra.setPosition(cant, 410);
        window.draw(tierra);
        tierra.setPosition(cant, 442);
        window.draw(tierra);
        tierra.setPosition(cant, 474);
        window.draw(tierra);
        tierra.setPosition(cant, 506);
        window.draw(tierra);
        }

        for (int i = 460; i < 478; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        window.draw(bloqueFlotante2);
        tierra.setPosition(cant,230);
        window.draw(tierra);
        tierra.setPosition(cant, 198);
        window.draw(tierra);
        tierra.setPosition(cant, 198);
        window.draw(tierra);
        tierra.setPosition(cant, 166);
        window.draw(tierra);
        tierra.setPosition(cant, 166);
        window.draw(tierra);
        }

        bloqueFlotante1.setPosition(14460, 250);
        window.draw(bloqueFlotante1);
        for (int i = 483; i < 487; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 250);
        window.draw(bloqueFlotante2);
        }
        bloqueFlotante3.setPosition(14610, 250);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(14900, 346);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(14930, 346);
        window.draw(bloqueFlotante3);

        bloqueFlotante2.setPosition(15155, 332);
        window.draw(bloqueFlotante2);
        piso1.setPosition(15155, 290);
        window.draw(piso1);
        tierra.setPosition(15155, 320);
        window.draw(tierra);

        bloqueFlotante2.setPosition(15400, 332);
        window.draw(bloqueFlotante2);
        piso1.setPosition(15400, 290);
        window.draw(piso1);
        tierra.setPosition(15400, 320);
        window.draw(tierra);

        for (int i = 520; i < 580; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 378);
        window.draw(bloqueFlotante2);
        }

        for (int i = 540; i < 565; i++) {
        int cant = i * 30;
        bloqueFlotante2.setPosition(cant, 243);
        window.draw(bloqueFlotante2);
        piso1.setPosition(cant, -294);
        window.draw(piso1);
        tierra.setPosition(cant, -262);
        window.draw(tierra);
        tierra.setPosition(cant, -230);
        window.draw(tierra);
        tierra.setPosition(cant, -198);
        window.draw(tierra);
        tierra.setPosition(cant, -166);
        window.draw(tierra);
        tierra.setPosition(cant, -134);
        window.draw(tierra);
        tierra.setPosition(cant, -102);
        window.draw(tierra);
        tierra.setPosition(cant, -70);
        window.draw(tierra);
        tierra.setPosition(cant, -38);
        window.draw(tierra);
        tierra.setPosition(cant, -6);
        window.draw(tierra);
        tierra.setPosition(cant, 26);
        window.draw(tierra);
        tierra.setPosition(cant, 58);
        window.draw(tierra);
        tierra.setPosition(cant, 90);
        window.draw(tierra);
        tierra.setPosition(cant, 122);
        window.draw(tierra);
        tierra.setPosition(cant, 154);
        window.draw(tierra);
        tierra.setPosition(cant, 186);
        window.draw(tierra);
        tierra.setPosition(cant, 218);
        window.draw(tierra);
        }

        bloqueFlotante1.setPosition(17070, 320);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(17100, 320);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(17130, 320);
        window.draw(bloqueFlotante3);

        bloqueFlotante2.setPosition(17250, 270);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(17070, 200);
        window.draw(bloqueFlotante2);

        bloqueFlotante3.setPosition(16950, 100);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(17070, 20);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(17100, 20);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(17130, 20);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(17160, 20);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(17190, 20);
        window.draw(bloqueFlotante3);

        bloqueFlotante2.setPosition(17320, -60);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(17320, -60);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(17130, -120);
        window.draw(bloqueFlotante2);

        bloqueFlotante3.setPosition(16950, -200);
        window.draw(bloqueFlotante3);

        bloqueFlotante2.setPosition(3910, 370);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(17540, -130);
        window.draw(bloqueFlotante2);

        bloqueFlotante2.setPosition(17690, -230);
        window.draw(bloqueFlotante2);

        bloqueFlotante1.setPosition(17890, -265);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(17920, -265);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(17950, -265);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(12110, 330);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(12140, 330);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12170, 330);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12200, 330);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(12230, 330);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(12430, 240);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(12460, 240);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12490, 240);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12520, 240);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(12550, 240);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(12830, 390);
        window.draw(bloqueFlotante1);
        bloqueFlotante3.setPosition(12860, 390);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(12740, 210);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(12770, 210);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12800, 210);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(12830, 210);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(12860, 210);
        window.draw(bloqueFlotante3);

        bloqueFlotante1.setPosition(13100, 310);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(13130, 310);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(13160, 310);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(13190, 310);
        window.draw(bloqueFlotante3);

        tierra.setPosition(11700,322);
        window.draw(tierra);
        tierra.setPosition(11700,290);
        window.draw(tierra);
        tierra.setPosition(11700,258);
        window.draw(tierra);

        bloqueFlotante1.setPosition(11840,240);
        window.draw(bloqueFlotante1);
        bloqueFlotante2.setPosition(11870, 240);
        window.draw(bloqueFlotante2);
        bloqueFlotante2.setPosition(11900, 240);
        window.draw(bloqueFlotante2);
        bloqueFlotante3.setPosition(11930, 240);
        window.draw(bloqueFlotante3);

     ///Dibujar al enemigo.
    for (auto& enemigo : enemigos) {
        window.draw(enemigo);
    }

    ///FUNGUS

    for (auto& enemigo_ : funEnemigos) {
        window.draw(enemigo_);
    }

    ///FALL

    for (auto& enemigoF : fallEnemigos) {
        window.draw(enemigoF);
    }

    ///Murcielagos
    for (auto& obss : vecobstaculos) {
        window.draw(obss);
}

    window.draw(llaveCasa1_sprite);
    window.draw(llaveCasa2_sprite);
    window.draw(llaveCasa3_sprite);

    ///Dibuja a Fein.
    window.draw(fein);


    if (win) {
        backgroundMusic.stop();

        if (wins.getStatus() != sf::Sound::Playing) { // Evitar reproducir múltiples veces simultáneamente
            wins.play();
        }
        sf::Vector2f viewCenter = view.getCenter();
        gameWinOverlay.setPosition(viewCenter.x - gameWinOverlay.getSize().x / 2, viewCenter.y - gameWinOverlay.getSize().y / 2);
        window.draw(gameWinOverlay);

        gameWinText.setPosition(viewCenter.x - gameWinText.getGlobalBounds().width / 2, viewCenter.y - gameWinText.getGlobalBounds().height / 2);
        window.draw(gameWinText);

        window.display();
        sf::sleep(sf::seconds(3));
        return true ;
    }

    if (isPaused) {
        backgroundMusic.pause();
        sf::Vector2f viewCenter = view.getCenter();
        overlay.setPosition(viewCenter.x - overlay.getSize().x / 2, viewCenter.y - overlay.getSize().y / 2);
        window.draw(overlay);

        sf::Text pauseText;
        pauseText.setFont(font);
        pauseText.setString("| |");
        pauseText.setCharacterSize(60);
        pauseText.setFillColor(sf::Color::White);
        pauseText.setStyle(sf::Text::Bold);
        pauseText.setPosition(viewCenter.x - pauseText.getGlobalBounds().width / 2,
                               viewCenter.y - pauseText.getGlobalBounds().height / 2);
        window.draw(pauseText);
    }

    if (isGameOver) {
        // Mostrar superposición de juego terminado
        if (gameOver.getStatus() != sf::Sound::Playing) { // Evitar reproducir múltiples veces simultáneamente
            gameOver.play();
        }
        backgroundMusic.stop();
        vida.stop();
        sf::Vector2f viewCenter = window.getView().getCenter();
        gameOverOverlay.setPosition(viewCenter.x - gameOverOverlay.getSize().x / 2, viewCenter.y - gameOverOverlay.getSize().y / 2);
        gameOverText.setPosition(viewCenter.x - gameOverText.getGlobalBounds().width / 2, viewCenter.y - gameOverText.getGlobalBounds().height / 2);
        window.draw(gameOverOverlay);
        window.draw(gameOverText);
        window.display();
        sf::sleep(sf::seconds(3));  // Pausa de 3 segundos antes de regresar al menú

        return true;
    }

    window.display();
    return false;
}

#endif // CLSNIVEL_H_INCLUDED
