#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

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

enum class side { LEFT, RIGHT, NONE };
const int NUM_BRANCHES = 6;

void updateBranchSprites(side branchPositions[], sf::Sprite branches[]);
void updateBranches(side branchPositions[], int seed);
void updateNPC(NPC& npc, float dt);

