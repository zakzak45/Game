#include "obstacle.hpp"

void InitObstacle(Obstacle& o) {
    o.sprite = LoadTexture("enemy.png");
    o.rect = { 800, 175, 100, 100 };
    o.speed = 150.0f;
}

void UpdateObstacle(Obstacle& o, int screenWidth) {
    o.rect.x -= o.speed * GetFrameTime();
    if (o.rect.x + o.rect.width < 0)
        o.rect.x = screenWidth;
}

void DrawObstacle(const Obstacle& o) {
    DrawTextureEx(o.sprite, { o.rect.x, o.rect.y }, 0.0f, o.rect.width / o.sprite.width, WHITE);
}

void UnloadObstacle(Obstacle& o) {
    UnloadTexture(o.sprite);
}
