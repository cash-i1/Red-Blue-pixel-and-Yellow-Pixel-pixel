#include <raylib.h>
#include <iostream>
#include <vector>

#include "globals.h"
#include "particles/particle.h"
#include "grid/grid.h"
#include "particles/types/red_particle.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(scr_width, scr_height, "Red Blue pixel and Yellow Pixel pixel");

    Grid grid = Grid();
    grid.init();

    RedParticle sample_p = RedParticle();
    sample_p.pos = Vector2 {20,20};
    bool test = false;
    while (!WindowShouldClose()) {
        // sample_p.col = BLUE;
        // sample_p.pos = Vector2 {
        //     (float)((int)GetMouseX()/(int)cell_size), //Please forgive me programming gods 🙏
        //     (float)((int)GetMouseY()/(int)cell_size)
        // };
        // grid.step();
        sample_p.step();
        if (test == false) {
            test = true;
            grid.try_add_particle(sample_p);
        }

        std::cout << sample_p.pos.y << std::endl;
        BeginDrawing();
            grid.draw();
        EndDrawing();
    }
}
