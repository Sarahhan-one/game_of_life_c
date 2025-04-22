#include "grid.h"
#include <stdlib.h>

Grid* CreateGrid(int width, int height, int cellSize) {
    Grid* grid = (Grid*)malloc(sizeof(Grid));
    if (!grid) return NULL;
    
    grid->rows = height / cellSize;
    grid->columns = width / cellSize;
    grid->cellSize = cellSize;
    
    grid->cells = (int**)malloc(grid->rows * sizeof(int*));
    if (!grid->cells) {
        free(grid);
        return NULL;
    }
    
    for (int i = 0; i < grid->rows; i++) {
        grid->cells[i] = (int*)calloc(grid->columns, sizeof(int));
        if (!grid->cells[i]) {
            for (int j = 0; j < i; j++) {
                free(grid->cells[j]);
            }
            free(grid->cells);
            free(grid);
            return NULL;
        }
    }
    
    return grid;
}

void DestroyGrid(Grid* grid) {
    if (!grid) return;
    
    for (int i = 0; i < grid->rows; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}

void ClearGrid(Grid* grid) {
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->columns; col++) {
            grid->cells[row][col] = 0;
        }
    }
}

void RenderGrid(Grid* grid) {  
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->columns; col++) {
            Color color = grid->cells[row][col] ? WHITE : (Color){55, 55, 55, 255};
            DrawRectangle(col * grid->cellSize, row * grid->cellSize, 
                          grid->cellSize - 1, grid->cellSize - 1, color);
        }
    }
}

void SetCellValue(Grid* grid, int row, int col, int value) {
    if (IsInBounds(grid, row, col))
        grid->cells[row][col] = value;
}

int GetCellValue(Grid* grid, int row, int col) {
    if (IsInBounds(grid, row, col))
        return grid->cells[row][col];
    return 0;
}

int IsInBounds(Grid* grid, int row, int col) {
    return row >= 0 && row < grid->rows && col >= 0 && col < grid->columns;
}

void FillRandomGrid(Grid* grid) {
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->columns; col++) {
            grid->cells[row][col] = (GetRandomValue(0, 4) == 4) ? 1 : 0;
        }
    }
}
