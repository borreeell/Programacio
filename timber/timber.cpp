// timber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Incloure llibreries
#include <iostream>
#include <sstream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "funcions.h"

// Espais de noms
using namespace std;
using namespace sf;

// -------------------------------------
// Enumeracions i constants globals
// -------------------------------------
const int NUM_CLOUDS = 3;

const float timeBarStartWidth = 400;
const float timeBarHeight = 80;

const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1075;

const float FPS_UPDATE_INTERVAL = 5.0f; // Cada 5 segons

int main()
{
    // -------------------------------------
    // Creacio i elements visuals
    // -------------------------------------
    VideoMode vm({ 1920, 1080 });
    RenderWindow window(vm, "Timber", State::Windowed);
    
    // Textura del fons
    Texture textureBackground("graphics/background.png");
    Sprite spriteBackground(textureBackground);

    // Textures dels arbres
    Texture textureTree1("graphics/tree.png");
    Texture textureTree2("graphics/tree2.png");

    Sprite spriteTree1(textureTree1);
    spriteTree1.setPosition({ 810, 0 });

    Sprite spriteTree2(textureTree2);
    spriteTree2.setPosition({ 0, -65 });

    Sprite spriteTree3(textureTree2);
    spriteTree3.setPosition({ 1500, - 150 });

    // Textura del jugador
    Texture texturePlayer("graphics/player.png");
    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition({ 580, 720 });

    // Textura de la lapida
    Texture textureRip("graphics/rip.png");
    Sprite spriteRip(textureRip);
    spriteRip.setPosition({ 600, 860 });

    // Textura de la destral
    Texture textureAxe("graphics/destral.png");
    Sprite spriteAxe(textureAxe);
    spriteAxe.setPosition({ 700, 830 });

    // Tronc volador
    Texture textureLog("graphics/log.png");
    Sprite spriteLog(textureLog);
    spriteLog.setPosition({ 810, 720 });

    // -------------------------------------
    // Entitats mobils (Abella + Nuvols)
    // -------------------------------------
    Texture textureBee("graphics/abella.png");
    Texture textureCloud("graphics/cloud.png");

    NPC bee(textureBee, 500, 400, -1, 2000);
    NPC clouds[NUM_CLOUDS] = {
        NPC(textureCloud, 100, 200, 1, -200),
        NPC(textureCloud, 250, 200, 1, -200),
        NPC(textureCloud, 500, 200, 1, -200)
    };

    // -------------------------------------
    // Textos i marcador
    // -------------------------------------
    Font font("fonts/KOMIKAP_.ttf");
    Font font2("fonts/04B_11__.ttf");

    Text messageText(font);
    Text scoreText(font);
    Text fpsText(font2);
    
    messageText.setString("Press Enter to start!");
    messageText.setCharacterSize(75);
    messageText.setFillColor(Color::White);
    
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin({ textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f });
    messageText.setPosition({ 1920 / 2, 1080 / 2 });

    scoreText.setCharacterSize(75);
    scoreText.setString("Score = 0");
    scoreText.setFillColor(Color::White);
    scoreText.setPosition({ 20, 20 });

    fpsText.setString("0 FPS");
    fpsText.setCharacterSize(40);
    fpsText.setFillColor(Color::White);
    fpsText.setPosition({ 1600, 20 });

    // -------------------------------------
    // Audio
    // -------------------------------------

    // Audio del jugador tallant
    SoundBuffer chopBuffer("sound/chop.wav");
    Sound chopSound(chopBuffer);

    // Audio de fi del temps
    SoundBuffer outTimeBuffer("sound/out_of_time.wav");
    Sound outTimeSound(outTimeBuffer);

    // Audio de mort
    SoundBuffer deathBuffer("sound/death.wav");
    Sound deathSound(deathBuffer);

    // -------------------------------------
    // Variables de joc
    // -------------------------------------
    Clock clock;
    Clock fpsClock;

    int score = 0;
    int fpsCounter = 0;
    int lives = 3;

    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
    float logSpeedX = 1000;
    float logSpeedY = -1500;
    float fpsUpdateTimer = 0.f;

    bool paused = true;
    bool acceptInput = false;
    bool logActive = false;

    side playerSide = side::LEFT;

    RectangleShape timeBar(Vector2f(timeBarStartWidth, timeBarHeight));

    timeBar.setFillColor(Color::Red);
    timeBar.setPosition({ 1920 / 2 - timeBarStartWidth / 2, 980 });

    // -------------------------------------
    // Configuracio branques
    // -------------------------------------
    Texture textureBranch("graphics/branch.png");
    side branchPositions[NUM_BRANCHES];
    Sprite branches[NUM_BRANCHES] = {
        Sprite(textureBranch),Sprite(textureBranch),Sprite(textureBranch),
        Sprite(textureBranch),Sprite(textureBranch),Sprite(textureBranch)
    };

    for (int i = 0; i < NUM_BRANCHES; i++) {
        branches[i].setTexture(textureBranch);
        branches[i].setPosition({ -2000, -2000 });

        branches[i].setOrigin({ 220, 20 });
        branchPositions[i] = side::LEFT;
    }

    // -------------------------------------
    // Bucle principal del joc
    // -------------------------------------
    while (window.isOpen()) {
        // Gestio d'events
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) window.close();

            if (const auto* key = event->getIf<Event::KeyPressed>()) {
                if (key->scancode == Keyboard::Scancode::Escape) window.close(); // Utilitza la tecla ESC per sortir del joc

                // Reiniciar el joc
                if (key->scancode == Keyboard::Scancode::Enter) {
                    paused = false;

                    // Reinicia el temps i la puntuacio
                    score = 0;
                    timeRemaining = 6;

                    for (int i = 0; i < NUM_BRANCHES; i++) {
                        branchPositions[i] = side::NONE;
                    }

                    // Assegura que la lapida esta amagada
                    spriteRip.setPosition({ 675, 2000 });

                    // Amaga el jugador
                    spritePlayer.setPosition({ 675, 660 });

                    acceptInput = true;
                }

                if (key->scancode == Keyboard::Scancode::Left) {
                    // Assegura que el jugador esta a la dreta
                    playerSide = side::LEFT;
                    
                    // Suma a la puntuacio
                    score++;

                    // Afegeix la puntuacio al temps restant
                    timeRemaining += (2 / score) + .15;

                    spriteAxe.setPosition({ AXE_POSITION_LEFT, spriteAxe.getPosition().y });
                    spritePlayer.setPosition({ 675, 720 });

                    updateBranches(branchPositions, score);

                    // Posa el tronc volador a l'esquerra
                    spriteLog.setPosition({ 810, 720 });
                    logSpeedX = 5000;
                    logActive = true;

                    acceptInput = false;

                    chopSound.play();
                }

                if (key->scancode == Keyboard::Scancode::Right) {
                    // Assegura que el jugador esta a la dreta
                    playerSide = side::RIGHT;

                    // Suma a la puntuacio
                    score++;

                    // Afegeix la puntuacio al temps restant
                    timeRemaining += (2 / score) + .15;

                    spriteAxe.setPosition({ AXE_POSITION_RIGHT, spriteAxe.getPosition().y });
                    spritePlayer.setPosition({ 1200, 720 });

                    updateBranches(branchPositions, score);

                    // Posa el tronc volador a la dreta
                    spriteLog.setPosition({ 810, 720 });
                    logSpeedX = -5000;
                    logActive = true;

                    acceptInput = false;

                    chopSound.play();
                }
            }
        }

        // -------------------------------------
        // Actualitzacio del joc
        // -------------------------------------
        if (!paused) {
            Time dt = clock.restart();

            timeRemaining -= dt.asSeconds();
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, 800));

            if (timeRemaining <= 0) {
                paused = true;

                messageText.setString("Out of time!");

                textRect = messageText.getLocalBounds();
                messageText.setOrigin({ (textRect.position.x + (textRect.size.x / 2.0f)), (textRect.position.y + (textRect.size.y / 2.0f)) });
            
                outTimeSound.play();
            }

            // Entitats mobils
            updateNPC(clouds[0], dt.asSeconds());
            updateNPC(clouds[1], dt.asSeconds());
            updateNPC(clouds[2], dt.asSeconds());
            updateNPC(bee, dt.asSeconds());

            stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            updateBranchSprites(branchPositions, branches);

            // Control del tronc volador
            if (logActive) {
                spriteLog.setPosition({ spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()), spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()) });
                
                if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
                    logActive = false;
                    spriteLog.setPosition({ 810, 720 });
                }
            }

            // Comprovar si al jugador l'ha tocat una branca
            if (branchPositions[5] == playerSide) {
                // Mort
                paused = true;
                acceptInput = false;

                // Mostra la lapida
                spriteRip.setPosition({ 525, 760 });

                // Canvia el text del missatge
                messageText.setString("SQUISHED!");

                textRect = messageText.getLocalBounds();
                messageText.setOrigin({ textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f });

                deathSound.play();
                lives - 1;
            }
        }

        // -------------------------------------
        // Dibuix
        // -------------------------------------
        window.clear();
        window.draw(spriteBackground);

        for (int i = 0; i < NUM_CLOUDS; i++) {
            window.draw(clouds[i].sprite);
        }

        for (int i = 0; i < NUM_BRANCHES; i++) {
            window.draw(branches[i]);
        }

        window.draw(spriteTree1);
        window.draw(spriteTree2);
        window.draw(spriteTree3);

        // Mostra el jugador nomes si no esta pausat
        if (!paused) {
            window.draw(spritePlayer);

            window.draw(spriteAxe);
        }

        window.draw(spriteLog);

        window.draw(spriteRip);
        
        window.draw(bee.sprite);
        
        window.draw(scoreText);
        
        window.draw(timeBar);

        window.draw(fpsText);

        if (paused) {
            window.draw(messageText);
        }

        window.display();

        // -------------------------------------
        // Comptador d'FPS
        // -------------------------------------
        fpsCounter++; // Suma un frame
        
        float elapsed = fpsClock.getElapsedTime().asSeconds();

        if (elapsed >= FPS_UPDATE_INTERVAL) {
            float fps = fpsCounter / elapsed;

            stringstream fpsStream;
            fpsStream << static_cast<int>(fps) << " FPS";
            fpsText.setString(fpsStream.str());

            fpsCounter = 0;
            fpsClock.restart();
        }
    }

    return 0;
}