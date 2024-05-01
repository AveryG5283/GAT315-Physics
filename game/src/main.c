#include "mathf.h"
#include "raymath.h"
#include "world.h"

#include <stdlib.h>
#include <assert.h>

#define MAX_BODIES 100

int main(void)
{
    InitWindow(1280, 720, "Physics Engine");
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose())
    {
        // update
        float dt = GetFrameTime();
        float fps = (float)GetFPS();

        Vector2 mousePosition = GetMousePosition();

        if (IsMouseButtonDown(0))
        {
            // creates new body when mouse is clicked using CreateBody method
            CreateBody(mousePosition);
        }

        // renders and draws stuff
        BeginDrawing();
        ClearBackground(BLACK);

        //stats
        DrawText(TextFormat("FPS: %.2f (%.2f ms)", fps, 1000 / fps), 10, 10, 20, LIME);
        DrawText(TextFormat("FRAME: %.4f", dt), 10, 30, 20, LIME);

        DrawCircle((int)mousePosition.x, (int)mousePosition.y, 20, RED);

        // iterates through bodies and draws them
        Body* currentBody = bodies;
        while (currentBody != NULL)
        {
            currentBody->position = Vector2Add(currentBody->position, currentBody->velocity);
            DrawCircle((int)currentBody->position.x, (int)currentBody->position.y, 10, RED);
            currentBody = currentBody->next;
        }

        EndDrawing();
    }

    CloseWindow();
    // bodies no longer need to be deleted here

    return 0;
}