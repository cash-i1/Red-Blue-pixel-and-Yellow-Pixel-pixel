#include <raylib.h>
#include <iostream>
#include <vector>

#include "globals.h"
#include "particles/particle.h"
#include "grid/grid.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(scr_width, scr_height, "Red Blue pixel and Yellow Pixel pixel");

    Grid grid = Grid();
    grid.init();
    while (!WindowShouldClose()) {
        Particle sample_p = Particle();
        sample_p.col = BLUE;
        sample_p.pos = Vector2 {
            (float)((int)GetMouseX()/(int)cell_size), //Please forgive me programming gods 🙏
            (float)((int)GetMouseY()/(int)cell_size)
        };

        grid.try_add_particle(sample_p);
        BeginDrawing();
            grid.draw();
        EndDrawing();
    }
}
