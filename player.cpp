#include "player.hpp"


Player::Player()
{  
    image =LoadTexture("GDash.jpeg");
    position.x =0;
    position.y=225;
    speedY=0;
    gravity=0.5f;
    jumpVelocity=-7.5f;
    isJumping=false;
}

Player::~Player(){
    UnloadTexture(image);
}

void Player::Draw()
{
    
    DrawTextureV(image,position,GREEN);
}
void Player::Update()
{
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) && !isJumping) { 
        speedY = jumpVelocity;
        isJumping = true;
    }

    //gravity and collision code
        position.y += speedY;
        speedY += gravity;

        if (position.y >= 225) {
            position.y = 225;
            isJumping = false;
            speedY = 0;
        }

}