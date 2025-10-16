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

int main()
{
    // -------------------------------------
    // Creacio i elements visuals
    // -------------------------------------
    VideoMode vm({ 1920, 1080 });
    RenderWindow window(vm, "Timber!!!", State::Windowed);
    
    // Textura del fons
    Texture textureBackground("graphics/background.png");
    Sprite spriteBackground(textureBackground);

    // Textura de l'arbre 1
    Texture textureTree1("graphics/tree.png");
    Sprite spriteTree1(textureTree1);
    spriteTree1.setPosition({ 810, 0 });

    // Textura del jugador
    Texture texturePlayer("graphics/player.png");
    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition({ 580, 720 });

    // -------------------------------------
    // Entitats mobils (Abella + Nuvols)
    // -------------------------------------
    Texture textureBee("graphics/bee.png");
    Texture textureCloud("graphics/cloud.png");

    NPC bee(textureBee, 500, 400, -1, 2000);
    NPC clouds[NUM_CLOUDS] = {
        NPC(textureCloud, 0, 200, 1, -200),
        NPC(textureCloud, 250, 200, 1, -200),
        NPC(textureCloud, 500, 200, 1, -200)
    };

    // -------------------------------------
    // Variables de joc
    // -------------------------------------
    Clock clock;

    // -------------------------------------
    // Bucle principal del joc
    // -------------------------------------
    while (window.isOpen()) {
        // Gestio d'events
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) window.close();
            if (const auto* key = event->getIf<Event::KeyPressed>()) {
                if (key->scancode == Keyboard::Scancode::Escape) window.close();
            }
        }

        // -------------------------------------
        // Actualitzacio del joc
        // -------------------------------------
        Time dt = clock.restart();

        // Entitats mobils
        updateNPC(clouds[0], dt.asSeconds());
        updateNPC(clouds[1], dt.asSeconds());
        updateNPC(clouds[2], dt.asSeconds());
        updateNPC(bee, dt.asSeconds());

        // -------------------------------------
        // Dibuix
        // -------------------------------------
        window.clear();
        window.draw(spriteBackground);

        for (int i = 0; i < NUM_CLOUDS; i++) {
            window.draw(clouds[i].sprite);
        }

        window.draw(spriteTree1);
        window.draw(spritePlayer);
        window.draw(bee.sprite);

        window.display();
    }

    return 0;
}

void updateNPC(NPC& npc, float dt) {
    if (!npc.active) {
        npc.speed = (rand() % npc.maxSpeed) * npc.sentit;
        float height = rand() % npc.maxHeight;
        npc.sprite.setPosition({ npc.posicioInicialX, height });
        npc.active = true;
    }
    else {
        npc.sprite.setPosition({
            npc.sprite.getPosition().x + npc.speed * dt,
            npc.sprite.getPosition().y
        });
        
        if (npc.sprite.getPosition().x < -200 || npc.sprite.getPosition().x > 200) npc.active = false;
    }
}
