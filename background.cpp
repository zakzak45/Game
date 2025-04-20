#include "background.hpp"

void InitBackground(Background& bg, const char* path, float speed) {
    bg.image = LoadTexture(path);
    bg.scroll = 0.0f;
    bg.speed = speed;
}

void UpdateBackground(Background& bg) {
    bg.scroll -= bg.speed;
    if (bg.scroll <= -bg.image.width * 2)
        bg.scroll = 0;
}

void DrawBackground(const Background& bg) {
    DrawTextureEx(bg.image, { bg.scroll, 20 }, 0.0f, 2.0f, RED);
    DrawTextureEx(bg.image, { bg.image.width * 2 + bg.scroll, 20 }, 0.0f, 2.0f, RED);
}

void UnloadBackground(Background& bg) {
    UnloadTexture(bg.image);
}
