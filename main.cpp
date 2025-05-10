#include "raylib.h"
#include "player.hpp"
#include "obstacle.hpp"
#include "background.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Geometry Dash ");
    SetTargetFPS(60);

    Player player;
    InitPlayer(player);

    Obstacle obstacle;
    InitObstacle(obstacle);

    Background back, mid, fore;
    InitBackground(back, "itachi.png", 1.0f);
    InitBackground(mid, "itachi.png", 0.9f);
    InitBackground(fore, "itachi.png", 2.0f);

    int score = 0;

    while (!WindowShouldClose()) {
        UpdateBackground(back);
        UpdateBackground(mid);
        UpdateBackground(fore);

        UpdateObstacle(obstacle, screenWidth);
        UpdatePlayer(player);
          
        

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawBackground(back);
        DrawBackground(mid);
        DrawBackground(fore);

        DrawObstacle(obstacle);
        DrawPlayer(player);
         
    
        

        if (CheckCollisionRecs(player.rect1, obstacle.rect)) {
             score--;
            DrawText("Game Over", screenWidth / 2 - MeasureText("Game Over", 40) / 2, screenHeight / 2 - 10, 20, RED);
            //break;
        }
        
      
        
        if (obstacle.rect.x < 0) {
            obstacle.rect.x = screenWidth;
            obstacle.rect.y = GetRandomValue(100, 300);
        }

        DrawText(TextFormat("Score:%d", score / 60), 10, 10, 20, BLACK);
        EndDrawing();
    }

    UnloadBackground(back);
    UnloadBackground(mid);
    UnloadBackground(fore);
    UnloadPlayer(player);
    UnloadObstacle(obstacle);

    CloseWindow();
    return 0;
}
