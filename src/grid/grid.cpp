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
            p.pos = Vector2{(float)x, (float)y};
            row.push_back(p);
        }
        vec.push_back(row);
    }
}

void Grid::draw() {
    if (IsWindowResized()) {
        Grid::reinit();
    } else {
        for (int x = 0; x < GetScreenWidth() / cell_size; x++) {
            for (int y = 0; y < GetScreenHeight() / cell_size; y++) {
                vec[x][y].draw();
            }
        }
    }
}

void Grid::add_particle_at_pos(Vector2 pos, Particle p) {
    // This is not recomended, use add_particle instead.
    p.pos = Vector2{pos.x, pos.y};
    vec[pos.x][pos.y] = p;
}

void Grid::add_particle(Particle p) {
    vec[p.pos.x][p.pos.y] = p;
}

void Grid::try_add_particle(Particle p) {
    // TODO: Make it so it will only place particle when there isnt a particle already there that isnt nothing paricle;
    Grid::add_particle(p);
}

void Grid::step() {
    for (int x = 0; x < GetScreenWidth() / cell_size; x++) {
        for (int y = 0; y < GetScreenHeight() / cell_size; y++) {
            vec[x][y].step();
        }
    }
}

void Grid::reinit() {
    vec.resize(GetScreenWidth());
    for (int x = 0; x < GetScreenWidth(); x++) {
        if (x >= vec.size()) {
            vec[x].resize(GetScreenHeight());
        } else {
            vec[x].resize(GetScreenHeight(), Particle()); // Fill new elements with default Particle values
        }
        for (int y = 0; y < GetScreenHeight(); y++) {
            vec[x][y].pos = Vector2{(float)x, (float)y};
        }
    }
}
