#include <raylib.h>
#include <iostream>
#include <vector>

#include "globals.h"
#include "particles/particle.h"
#include "grid/grid.h"

int main() {
    InitWindow(scr_width, scr_height, "Red Blue pixel and Yellow Pixel pixel");

    Grid grid = Grid();

    while (!WindowShouldClose()) {
        for (int x = 0; x < grid_width; x++) {
            for (int y = 0; y < grid_height; y++) {
                // grid.vec[x][y].draw();
            }
        }
    }
}
