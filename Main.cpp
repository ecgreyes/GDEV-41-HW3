#include <raylib.h>
#include <iostream>
#include <cmath>

int main() {
    Vector2 cuePos{300.0f, 300.0f};
    Vector2 initialPos;
    Vector2 dragPos;
    float fMagnitude;
    float timestep = GetFrameTime(); //multiply to movement
    Rectangle up = {125, 0, 550, 50};
    Rectangle down = {125, 550, 550, 50};
    Rectangle left = {0, 125, 50, 350};
    Rectangle right = {750, 125, 50, 350};
    int indicator;
    

    InitWindow(800, 600, "Basic Physics and Collision");

    const int targetFPS = 60;

    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) {

        //Takes initial position on press and position when dragged away and gets the distance.
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            initialPos = GetMousePosition();
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            dragPos = GetMousePosition();
        }
        fMagnitude = sqrt(pow((dragPos.x - initialPos.x), 2) + pow((dragPos.y - initialPos.y), 2));

        //cue position
        cuePos = GetMousePosition();

        //check collision circle-rec
        if(CheckCollisionCircleRec(cuePos, 50, up)) {
            indicator = 1;
        } else if(CheckCollisionCircleRec(cuePos, 50, down)){
            indicator = 1;
        } else if(CheckCollisionCircleRec(cuePos, 50, left)){
            indicator = 1;
        } else if(CheckCollisionCircleRec(cuePos, 50, right)){
            indicator = 1;
        } else {
            indicator = 0;
        }
        

        BeginDrawing();

        //Board
        DrawRectangle(0, 0, 800, 600, GREEN);

        //Holes
        DrawCircle(50, 50, 50, BLACK); //upperleft
        DrawCircle(50, 550, 50, BLACK); //lowerleft
        DrawCircle(750, 50, 50, BLACK); //upperright
        DrawCircle(750, 550, 50, BLACK); //lowerright

        //Sides
        DrawRectangleRec(up, BROWN); //up
        DrawRectangleRec(down, BROWN); //down
        DrawRectangleRec(left, BROWN); //left
        DrawRectangleRec(right, BROWN); //right

        //Cue Ball
        DrawCircleV(cuePos, 30, WHITE);

        //Billiard Balls
        DrawCircle(500, 300, 30, BLUE);
        DrawCircle(550, 250, 30, BLUE);
        DrawCircle(550, 350, 30, BLUE);

        DrawText(TextFormat("testcollide: %i", indicator), 10, 40, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}