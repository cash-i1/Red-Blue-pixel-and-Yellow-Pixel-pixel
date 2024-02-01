#include <raylib.h>
#include <iostream>
#include <vector>

#include "globals.h"
#include "particles/particle.h"
#include "grid/grid.h"

int main() {
    InitWindow(scr_width, scr_height, "Red Blue pixel and Yellow Pixel pixel");

    Grid grid = Grid();
    grid.init();
    while (!WindowShouldClose()) {
        BeginDrawing();
            grid.draw();
        EndDrawing();
    }
}
