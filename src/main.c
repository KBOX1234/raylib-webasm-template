// main.c
#include "raylib.h"

int main(void) {
    InitWindow(1920, 1080, "raylib [web] example");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, WebAssembly!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

