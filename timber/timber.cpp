// timber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Incloure llibreries
#include <iostream>

#include <SFML/Graphics.hpp>

// Espais de noms
using namespace std;
using namespace sf;

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

int main()
{
    // -----------------------------
    // Creacio i elements visuals
    // -----------------------------
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

    // Textura de l'abella
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");



    // -----------------------------
    // Bucle principal del joc
    // -----------------------------
    while (window.isOpen()) {
        // Gestio d'events
        while (const optional event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
        }

        // -----------------------------
        // Actualitzacio del joc
        // -----------------------------

        // -----------------------------
        // Dibuix
        // -----------------------------
        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree1);
        window.draw(spritePlayer);

        window.display();
    }

    return 0;
}
