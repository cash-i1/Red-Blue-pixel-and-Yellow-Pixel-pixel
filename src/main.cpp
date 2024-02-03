#include <raylib.h>
#include <iostream>
#include <vector>

#include "globals.h"
#include "particles/particle.h"
#include "grid/grid.h"
// #include "particles/types/red_particle.h"
#include "particles/types/all_types.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(scr_width, scr_height, "Red Blue pixel and Yellow Pixel pixel");

    Grid grid = Grid();
    grid.init();
    
    Particle::Type selected_particle;

    while (!WindowShouldClose()) {
        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_Q)) {
            selected_particle = Particle::RED_P;
            std::cout << "selected red\n";
        } 
        if (IsKeyPressed(KEY_W)) {
            selected_particle = Particle::BLUE_P;
            std::cout << "selected blue\n";
        } 

        if (IsKeyPressed(KEY_E)) {
            selected_particle = Particle::YELLOW_P;
            std::cout << "selected yellow\n";
        } 
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

            if (selected_particle == Particle::RED_P) {
                RedParticle p;    //this is 
                p.pos = Vector2 {
                    (float)((int)GetMouseX()/(int)cell_size), //Please forgive me programming gods 🙏
                    (float)((int)GetMouseY()/(int)cell_size)
                };
                grid.try_add_particle(p, true);
                std::cout << "added particle (t: " << selected_particle << ", id: " << p.id << ")\n";
            }
            if (selected_particle == Particle::BLUE_P) {
                BlueParticle p;    //this is 
                p.pos = Vector2 {
                    (float)((int)GetMouseX()/(int)cell_size), //Please forgive me programming gods 🙏
                    (float)((int)GetMouseY()/(int)cell_size)
                };
                grid.try_add_particle(p, true);
                std::cout << "added particle (t: " << selected_particle << ", id: " << p.id << ")\n";
            }
            if (selected_particle == Particle::YELLOW_P) {
                YellowParticle p;    //this is 
                p.pos = Vector2 {
                    (float)((int)GetMouseX()/(int)cell_size), //Please forgive me programming gods 🙏
                    (float)((int)GetMouseY()/(int)cell_size)
                };
                grid.try_add_particle(p, true);
                std::cout << "added particle (t: " << selected_particle << ", id: " << p.id << ")\n";
            }
        }
        
        grid.step();
        BeginDrawing();
            grid.draw();
        EndDrawing();

    }
}
