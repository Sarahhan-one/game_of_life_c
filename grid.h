#ifndef GRID_H
#define GRID_H

#include "raylib.h"

typedef struct {
    int rows;
    int columns;
    int cellSize;
    int** cells;
} Grid;

Grid* CreateGrid(int width, int height, int cellSize);
void DestroyGrid(Grid* grid);
void ClearGrid(Grid* grid);
void RenderGrid(Grid* grid);  
void SetCellValue(Grid* grid, int row, int col, int value);
int GetCellValue(Grid* grid, int row, int col);
int IsInBounds(Grid* grid, int row, int col);
void FillRandomGrid(Grid* grid);

#endif 