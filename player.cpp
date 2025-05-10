#include "player.hpp"

void InitPlayer(Player& p) {
    p.sprite = LoadTexture("GDash.jpeg");
    p.rect1 = { 400, 150, 120, 100 };
    p.position = { 0, 225 };
    p.speedY = 0;
    p.isJumping = false;
}

void UpdatePlayer(Player& p) {
    if ((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) && !p.isJumping) {
        p.speedY = -7.5f;
        p.isJumping = true;
    }

    p.position.y += p.speedY;
    p.speedY += 0.5f;

    if (p.position.y >= 225) {
        p.position.y = 225;
        p.speedY = 0;
        p.isJumping = false;
    }
}

void DrawPlayer(const Player& p) {
   DrawTextureEx(p.sprite, { p.rect1.x, p.rect1.y }, 0.0f, p.rect1.width / p.sprite.width, WHITE);
}

void UnloadPlayer(Player& p) {
    UnloadTexture(p.sprite);
}
