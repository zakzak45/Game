#include "raylib.h"
#include "player.hpp"  //local library player.hpp ,you may need to link these three files together
//oky bro for obstacles it better to for loops and stuff and if u can resize the sprite and update the rectangle to be a sprite  and will just be left with fine tuning im gonna get some sleep 



int main() {
    // This is just the initialisation 
    //you can move all the code  too if you like 
    const int screenWidth = 800;
    const int screenHeight = 450;


    //scrolling floats for a moving background
    float scrollingBack =0.0f;
    float scrollingMid =0.0f;
    float scrollingFore =0.0f;
    


     //initiolizes the window
    InitWindow(screenWidth, screenHeight, "Geometry dash");

    //now inoder to make this background move i need back,mid,fore textures now for creativity u can add diff images to create an effect of changing levels
    Texture2D background = LoadTexture("itachi.png");// 
    Texture2D midground =  LoadTexture("itachi.png");// 
    Texture2D foreground = LoadTexture("itachi.png");// 

    SetTargetFPS(60); // the game will run on 60 frames per second
  
    //just bringing that class i created with all tht good stuff 
    Player player1;
    float obstacleSpeed=150.0f;//yeah dawg if u like just use oop here
    Rectangle obstacle =Rectangle{800,175,100,100};
    //game score
    int score = 0;

    // Main game loop
    while (!WindowShouldClose())
    {
    //moving them back u can adjust the speed
    scrollingBack-=1.0f;
    scrollingMid -=0.9f;
    scrollingFore -=2.0f;
    obstacle.x -= obstacleSpeed*GetFrameTime();//left it will go
    if(obstacle.x +obstacle.width<0) obstacle.x =screenWidth;//just making sure it resets 



    if(scrollingBack <= -background.width*2) scrollingBack =0;
    if(scrollingMid <=  -midground.width*2) scrollingMid =0;
    if(scrollingFore <= -foreground.width*2) scrollingFore =0;

        //This part not gonna lie is research,I wanted to find out how to create moving objects but sadly i cant see it,Bro thts literally programming


        //
        player1.Update();
        score++; //this is the same for C, C++ and C#, but this as you know is for updating the score

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);
         
        
        //Draws background image twice
        DrawTextureEx(background, (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, RED);
        DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 2.0f, RED);

        // Draw midground image twice
        DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, RED);
        DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, RED);

        // Draw foreground image twice
        DrawTextureEx(foreground, (Vector2){ scrollingFore, 20 }, 0.0f, 2.0f, RED);
        DrawTextureEx(foreground, (Vector2){ foreground.width*2 + scrollingFore, 20 }, 0.0f, 2.0f, RED);
       
        DrawRectangle(obstacle.x,obstacle.y,obstacle.width,obstacle.height,WHITE);
        //brings that sprite i created and draws it or loads it
        player1.Draw();
   
        DrawText(TextFormat("Score: %1", score /60), 10, 10, 20, BLACK); //since we using 60 frames per second am dividing the score by 60 it can fit the frame you set.
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    CloseWindow(); // Close window and OpenGL context

    return 0;
}


