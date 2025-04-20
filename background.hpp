#pragma once
#include "raylib.h"

struct Background {
    Texture2D image;
    float scroll;
    float speed;
};

void InitBackground(Background& bg, const char* path, float speed);
void UpdateBackground(Background& bg);
void DrawBackground(const Background& bg);
void UnloadBackground(Background& bg);
