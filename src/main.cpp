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
        Particle sample_p = Particle();
        sample_p.col = BLUE;
        grid.add_particle_at_pos(Vector2{GetMouseX()/(float)cell_size, GetMouseY()/(float)cell_size}, sample_p);
        BeginDrawing();
            grid.draw();
        EndDrawing();
    }
}
