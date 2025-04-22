# Conway's Game of Life

This is a implementation of Conway's Game of Life using the RayLib framework in C.
![Image](https://github.com/user-attachments/assets/91dcd7aa-ad69-4add-9eeb-0f4091ee0829)

## Overview

This simulation was inspired by [Nick Koumaris's Game of Life tutorial](https://youtu.be/daFYGrXq0aw?si=kK4c-jR6ZiQ2jTmI) originally written in C++. While this version is implemented in C, it follows the core structure and logic of the original. 

The project was motivated by [DMTPark's fascinating tetration simulation (power tower fractal)](https://youtu.be/mIxrcXrrxAI?si=wn-ujnqHFbpoUmma) that demonstrates the beauty inherent in mathematical patterns. As someone more familiar with C++, this project served as an opportunity to learn C and RayLib fundamentals before attempting more complex simulations. I specifically chose RayLib for their lightweight nature and compatibility with low-level hardware, making them ideal for future implementation on memory display LCDs and embedded systems.

## Files

- `main.c`: Program entry point
- `Simulation.c` and `Simulation.h`: Core game logic and simulation handling
- `grid.c` and `grid.h`: Grid management and cell state tracking
- `Makefile`: Project build configuration

## Controls

- **SPACE**: Start or pause the simulation
- **R**: Populate the grid with random alive/dead cells
- **C**: Clear the grid completely
- **Left Click**: Toggle a cell between alive/dead states

## Building the Project

Prerequisites
- RayLib must be installed on your system
- Installation instructions: [RayLib GitHub Repository](https://github.com/raysan5/raylib)
  
1. Clone the repository:
   ```bash
   git clone https://github.com/Sarahhan-one/game_of_life
   ```

2. Navigate to the project directory:
   ```bash
   cd game_of_life/srcs
   ```

3. Build using Make:
   ```bash
   make
   ```

4. Run the simulation:
   ```bash
   ./main
   ```

