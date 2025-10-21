// timber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Incloure llibreries
#include <iostream>
#include <sstream>
#include <ctime>

#include <SFML/Graphics.hpp>

// Espais de noms
using namespace std;
using namespace sf;

// -------------------------------------
// Enumeracions i constants globals
// -------------------------------------
const int NUM_CLOUDS = 3;
const int NUM_BRANCHES = 6;

const float timeBarStartWidth = 400;
const float timeBarHeight = 80;

const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1075;

enum class side { LEFT, RIGHT, NONE };

// -------------------------------------
// Estructura NPC (Abella/Nuvols)
// -------------------------------------
struct NPC {
    Sprite sprite;
    bool active;
    float speed;
    int maxHeight;
    int maxSpeed;
    int sentit; // 1 = dreta, -1 esquerra
    float posicioInicialX;

    NPC(Texture& texture, int maxHeight_, int maxSpeed_, int sentit_, float posicioInicialX_)
        :sprite(texture), active(false), speed(0),
        maxHeight(maxHeight_), maxSpeed(maxSpeed_),
        sentit(sentit_), posicioInicialX(posicioInicialX_) {
    }
}; 

// -------------------------------------
// Prototips de funcions
// -------------------------------------
void updateNPC(NPC&, float);
void updateBranchSprites(side[], Sprite[]);
void updateBranches(side branchPositions[], int seed);

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
    Texture textureAxe("graphics/axe.png");
    Sprite spriteAxe(textureAxe);
    spriteAxe.setPosition({ 700, 830 });

    // Tronc volador
    Texture textureLog("graphics/log.png");
    Sprite spriteLog(textureLog);
    spriteLog.setPosition({ 810, 720 });

    // -------------------------------------
    // Entitats mobils (Abella + Nuvols)
    // -------------------------------------
    Texture textureBee("graphics/bee.png");
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
    Text messageText(font);
    FloatRect textRect = messageText.getLocalBounds();
    Text scoreText(font);
    
    messageText.setString("Press Enter to start!");
    messageText.setCharacterSize(75);
    messageText.setFillColor(Color::White);
    messageText.setOrigin({ textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f });
    messageText.setPosition({ 1920 / 2, 1080 / 2 });

    scoreText.setCharacterSize(75);
    scoreText.setString("Score = 0");
    scoreText.setFillColor(Color::White);
    scoreText.setPosition({ 20, 20 });

    // -------------------------------------
    // Variables de joc
    // -------------------------------------
    Clock clock;

    int score = 0;

    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

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
                    logSpeedX = -5000;
                    logActive = true;

                    acceptInput = false;
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

                    // Posa el tronc volador a l'esquerra
                    spriteLog.setPosition({ 810, 720 });
                    logSpeedX = -5000;
                    logActive = true;

                    acceptInput = false;
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

                // Amaga el jugador
                spritePlayer.setPosition({ 2000, 660 });

                // Canvia el text del missatge
                messageText.setString("SQUISHED!");
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

        window.draw(spritePlayer);

        window.draw(spriteAxe);

        window.draw(spriteLog);

        window.draw(spriteRip);
        
        window.draw(bee.sprite);
        
        window.draw(scoreText);
        
        window.draw(timeBar);

        if (paused) window.draw(messageText);

        window.display();
    }

    return 0;
}

void updateNPC(NPC& npc, float dt) {
    if (!npc.active) {
        npc.speed = (rand() % npc.maxSpeed) * npc.sentit;
        float height = static_cast<float>(rand() % npc.maxHeight);
        npc.sprite.setPosition({ npc.posicioInicialX, height });
        npc.active = true;
    }
    else {
        npc.sprite.setPosition({
            npc.sprite.getPosition().x + npc.speed * dt,
            npc.sprite.getPosition().y
        });
        
        if (npc.sprite.getPosition().x < -200 || npc.sprite.getPosition().x > 2000) npc.active = false;
    }
}

void updateBranchSprites(side branchPositions[], Sprite branches[]) {
    for (int i = 0; i < NUM_BRANCHES; i++) {
        float height = i * 150;

        if (branchPositions[i] == side::LEFT) {
            branches[i].setPosition({ 610, height });
            branches[i].setRotation(degrees(180));
        }
        else if (branchPositions[i] == side::RIGHT) {
            branches[i].setPosition({ 1330, height });
            branches[i].setRotation(degrees(0));
        }
        else {
            branches[i].setPosition({ 3000, height });
        }
    }
}

void updateBranches(side branchPositions[], int seed) {
    for (int j = NUM_BRANCHES - 1; j > 0; j--) {
        branchPositions[j] = branchPositions[j - 1];
    }

    srand((int)time(0) + seed);

    int r = rand() % 5;
    switch (r) {
        case 0:
            branchPositions[0] = side::LEFT;
            break;
        case 1:
            branchPositions[0] = side::RIGHT;
            break;
        default:
            branchPositions[0] = side::NONE;
            break;
    }
}