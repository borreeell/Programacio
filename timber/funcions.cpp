#include <iostream>

#include <SFML/Graphics.hpp>
#include "funcions.h"

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