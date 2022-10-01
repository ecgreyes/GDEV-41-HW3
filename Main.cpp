#include <raylib.h>
#include <iostream>

int main() {

    InitWindow(800, 600, "Basic Physics and Collision");

    const int targetFPS = 60;

    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) {
        BeginDrawing();

        //Board
        DrawRectangle(0, 0, 800, 600, GREEN);

        //Holes
        DrawCircle(50, 50, 50, BLACK); //upperleft
        DrawCircle(50, 550, 50, BLACK); //lowerleft
        DrawCircle(750, 50, 50, BLACK); //upperright
        DrawCircle(750, 550, 50, BLACK); //lowerright

        //Sides
        DrawRectangle(125, 0, 550, 50, BROWN); //up
        DrawRectangle(125, 550, 550, 50, BROWN); //down
        DrawRectangle(0, 125, 50, 350, BROWN); //left
        DrawRectangle(750, 125, 50, 350, BROWN); //right

        //Cue Ball
        DrawCircle(300, 300, 30, WHITE);

        //Billiard Balls
        DrawCircle(500, 300, 30, BLUE);
        DrawCircle(550, 250, 30, BLUE);
        DrawCircle(550, 350, 30, BLUE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}