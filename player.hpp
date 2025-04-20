#pragma once
#include "raylib.h"

struct Player {
    Texture2D sprite;
    Vector2 position;
    Rectangle rect1;
    float speedY;
    bool isJumping;
};

void InitPlayer(Player& p);
void UpdatePlayer(Player& p);
void DrawPlayer(const Player& p);
void UnloadPlayer(Player& p);
