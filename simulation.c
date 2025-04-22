#include "simulation.h"

int CountLiveNeighbours(Grid* grid, int row, int col) {
    int count = 0;
    int neighbours[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0,  -1},          { 0, 1},
        {1,  -1}, { 1, 0}, { 1, 1}
    };

    for (int i = 0; i < 8; i++) {
        int r = (row + neighbours[i][0] + grid->rows) % grid->rows;
        int c = (col + neighbours[i][1] + grid->columns) % grid->columns;

        if (IsInBounds(grid, r, c) && GetCellValue(grid, r, c) == 1) {
            count++;
        }
    }
    return count;
}

void UpdateSimulation(Grid* grid, Grid* nextGrid) {
    // Calculate next generation
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->columns; j++) {
            int liveNeighbours = CountLiveNeighbours(grid, i, j);
            int currentCell = GetCellValue(grid, i, j);

            // Apply Game of Life rules
            if (currentCell == 1) {
                if (liveNeighbours < 2 || liveNeighbours > 3)
                    SetCellValue(nextGrid, i, j, 0);
                else
                    SetCellValue(nextGrid, i, j, 1);
            } else {
                if (liveNeighbours == 3)
                    SetCellValue(nextGrid, i, j, 1);
                else
                    SetCellValue(nextGrid, i, j, 0);
            }
        }
    }
    
    // Copy nextGrid to grid
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->columns; j++) {
            grid->cells[i][j] = nextGrid->cells[i][j];
        }
    }
}
