#include <stdio.h>
#include "raylib.h"
#include "grid.h"
#include "simulation.h"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define CELL_SIZE 25

int main(void) {
    const Color BACKGROUND_COLOR = (Color){169, 169, 169, 255};
    int FPS = 12;
    int simRunning = 0;  
    int startPage = 1;   

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    // Create grids
    Grid* grid = CreateGrid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    Grid* nextGrid = CreateGrid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // Main game loop
    while (!WindowShouldClose()) {
        // Input handling
        if (startPage) {
            if (IsKeyPressed(KEY_SPACE)) {
                startPage = 0; 
            }
        } else {
            if (IsKeyPressed(KEY_SPACE)) {
                simRunning = !simRunning; 
            }

            if (IsKeyPressed(KEY_C)) {
                ClearGrid(grid);  
            }

            if (IsKeyPressed(KEY_R)) {
                FillRandomGrid(grid);  
            }

            if (!simRunning && IsMouseButtonDown(0)) {
                int x = GetMouseX();
                int y = GetMouseY();
                int col = x / CELL_SIZE;
                int row = y / CELL_SIZE;
                SetCellValue(grid, row, col, 1); 
            }
        }

        // Update simulation
        if (!startPage && simRunning) {
            UpdateSimulation(grid, nextGrid);
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);  

        if (startPage) {
            DrawText("Game of Life", 250, 100, 30, BLACK);
            DrawText("Press Space to start the simulation", 200, 200, 20, BLACK);
            DrawText("Press C to clear the board", 200, 230, 20, BLACK);
            DrawText("Press R to randomly repopulate", 200, 260, 20, BLACK);
            DrawText("Click to toggle a cell between alive and dead", 200, 290, 20, BLACK);
        } else {
            RenderGrid(grid);
        }

        EndDrawing();
    }

    // Cleanup
    DestroyGrid(grid);
    DestroyGrid(nextGrid);
    CloseWindow();

    return 0;
}
