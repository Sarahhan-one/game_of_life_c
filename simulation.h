#ifndef SIMULATION_H
#define SIMULATION_H

#include "grid.h"

int CountLiveNeighbours(Grid* grid, int row, int col);
void UpdateSimulation(Grid* grid, Grid* nextGrid);

#endif 