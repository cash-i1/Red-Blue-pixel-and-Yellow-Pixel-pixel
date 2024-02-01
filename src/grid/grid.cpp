#include "grid.h"
#include "../particles/particle.h"
#include "raylib.h"
#include <vector>
#include <iostream>
Grid::Grid() {
    
} 

void Grid::init() {
    for (int x = 0; x < grid_width; x++) {
        std::vector<Particle> row;
        for (int y = 0; y < grid_height; y++) {
            Particle p = Particle();
            p.col = RED;
            p.pos = Vector2{(float)x, (float)y};
            std::cout << p.col.a;
            row.push_back(p);
        }
        std::cout << std::endl;
        vec.push_back(row);
    }
}

void Grid::draw() {
    for (int x = 0; x < grid_width; x++) {
        for (int y = 0; y < grid_height; y++) {
            vec[x][y].draw();
        }
    }
}
