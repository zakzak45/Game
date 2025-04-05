#pragma once//only included once to avoid duplicates definations
#include "raylib.h"
 

//well just realized oop is better for this job so since we can reuse methods multiple times


class Player{
   public :
   float x,y;
   float speedY;
   bool isJumping;
   float gravity=0.5f;
   float jumpVelocity =-7.5f;
   Player();//constructor
   ~Player();//destructor
   void Draw();
   void Update();
  private:
  Texture2D image;//we need an image of  the sprite
  Vector2 position;
};