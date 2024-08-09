#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hello Human"); // create window

    bool pause = false; 
    bool collision1 = false;
    bool collision2 = false; 

    int playerWidth = 40; //player size X
    int playerHeight = 80; //player size Y 

    Vector2 player1Pso = { (float)playerWidth *2, ((float)screenHeight / 2) - (playerHeight/2) }; //position
    Vector2 player2Pso = { screenWidth - playerWidth *2, (float)screenHeight / 2 - (playerHeight / 2) }; //position
  
    Rectangle player1 = { player1Pso.x, player1Pso.y, playerWidth, playerHeight }; // player 1
    Rectangle player2 = { player2Pso.x, player2Pso.y, playerWidth, playerHeight }; // player 2

    Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }; // ball 
    Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 20;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W)) if (player1.y - 3.0f > 0 ) player1.y -= 3.0f;
        if (IsKeyDown(KEY_S)) if (player1.y + 3.0f < (screenHeight - playerHeight)) player1.y += 3.0f;
        if (IsKeyDown(KEY_UP)) if (player2.y - 3.0f > 0) player2.y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) if (player2.y + 3.0f < (screenHeight - playerHeight)) player2.y += 3.0f;
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Check walls collision for bouncing
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

        collision1 = CheckCollisionCircleRec(ballPosition, ballRadius, player1);
        collision2 = CheckCollisionCircleRec(ballPosition, ballRadius, player2);
        if (collision1) ballSpeed.x *= -1.0, ballSpeed.y *= -1.0f;
        if (collision2) ballSpeed.x *= -1.0, ballSpeed.y *= -1.0f;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLUE);

        DrawText("Im Blue DA BE DEE DA BE DAA", 100 , 40, 40, WHITE);
        DrawCircleV(ballPosition, (float)ballRadius, MAROON);
        DrawRectangleRec ( player1, WHITE);
        DrawRectangleRec ( player2, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}