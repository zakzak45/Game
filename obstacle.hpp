#pragma once
#include "raylib.h"

struct Obstacle {
    Texture2D sprite;
    Rectangle rect;
    float speed;
};

void InitObstacle(Obstacle& o);
void UpdateObstacle(Obstacle& o, int screenWidth);
void DrawObstacle(const Obstacle& o);
void UnloadObstacle(Obstacle& o);
