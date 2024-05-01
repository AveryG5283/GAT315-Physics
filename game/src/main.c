#include "body.h"
#include "raylib.h"
#include "mathf.h"
#include "raymath.h"

#include <stdlib.h>
#include <assert.h>

#define MAX_BODIES 100

int main(void)
{
    InitWindow(1280, 720, "Physics Engine");
    SetTargetFPS(60);

    // Body* bodies = new Body[] (thats what the next line does)
    Body* bodies = (Body*)malloc(sizeof(Body) * MAX_BODIES); //malloc allocates bytes
    assert(bodies); // assert(bodies) also does the same thing basically

    int bodyCount = 0;

    // game loop
    while (!WindowShouldClose())
    {
        // update
        float dt = GetFrameTime(); 
        float fps = (float)GetFPS();

        Vector2 position = GetMousePosition();

        if (IsMouseButtonDown(0))
        {
            bodies[bodyCount].position = position;
            bodies[bodyCount].velocity = CreateVector2(GetRandomFloatValue(-5, 5), GetRandomFloatValue(-5, 5));
            bodyCount++;
        }

        // renders and draws stuff
        BeginDrawing();
        ClearBackground(BLACK);

        //stats
        DrawText(TextFormat("FPS: %.2f (%.2f ms)", fps, 1000 / fps), 10, 10, 20, LIME);
        DrawText(TextFormat("FRAME: %.4f", dt), 10, 30, 20, LIME);

        DrawCircle((int)position.x, (int)position.y, 20, RED);

        for (int i = 0; i < bodyCount; i++)
        {
            bodies[i].position = Vector2Add(bodies[i].position, bodies[i].velocity);
            DrawCircle((int)bodies[i].position.x, (int)bodies[i].position.y, 10, RED);
        }


        EndDrawing();
    }

    CloseWindow();
    free(bodies); // have to free (delete) bodies

    return 0;
}