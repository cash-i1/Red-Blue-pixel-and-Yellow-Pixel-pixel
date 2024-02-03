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

void Grid::add_particle(Particle p, bool replace) {
    if (replace) {
        for (int x = 0; x < vec.size(); x++) {
            for (int y = 0; y < vec[x].size(); y++) {
                if (vec[x][y].type == p.type) {
                    vec[x][y] = Particle();
                }
            }
        }
    }
    vec[p.pos.x][p.pos.y] = p;
}

void Grid::try_add_particle(Particle p, bool replace) {
    // TODO: Make it so it will only place particle when there isnt a particle already there that isnt nothing paricle;
    Grid::add_particle(p, replace);
}


bool Grid::can_move(Particle p) {
    if (p.pos.x < vec.size() - 1 && p.pos.x >= 1 && p.pos.y < vec[0].size() - 1 && p.pos.y >= 1) {
        return true;
    }

    return false;
}

void Grid::step() {
    for (int x = 0; x < GetScreenWidth() / cell_size; x++) {
        for (int y = 0; y < GetScreenHeight() / cell_size; y++) {
            // std::cout << "Indexing: " << x << ", " << y << "; " << vec.size() << ", " << vec[x].size() << std::endl;
            if (Grid::can_move(vec[x][y])) {
                Particle* p = &vec[x][y];
                
                vec[p->pos.x][p->pos.y] = *p;
                if (p->pos.x != x && p->pos.y != y) {

                    vec[x][y] = Particle();
                }

                p->step();
            }
        }
    }
}

// void Grid::reinit() {
//     int y_resize = (GetScreenWidth() / cell_size) +10;
//     int x_resize = (GetScreenHeight() / cell_size) +10;
//
//     vec.resize(y_resize);
//
//     std::cout << "Current vec dim: y: " << vec.size() << ", x: " << vec[0].size() << "; resize: y: " << y_resize << ", x:" << x_resize << std::endl;
//     for (int x = 0; x < y_resize; x++) {
//         if (vec[x].size() != x_resize) {
//
//             vec[x].resize(x_resize, Particle()); // +1 Fill new elements with default Particle values
//         }
//     }
// }

void Grid::reinit() {
    int y_resize = (GetScreenWidth() / cell_size) + 1;
    int x_resize = (GetScreenHeight() / cell_size) + 1;

    std::vector<std::vector<Particle>> temp_vec(y_resize);

    std::cout << "Current vec dim: y: " << vec.size() << ", x: " << (vec.empty() ? 0 : vec[0].size()) << "; resize: y: " << y_resize << ", x:" << x_resize << std::endl;

    for (int y = 0; y < y_resize; y++) {
        if (y < vec.size()) {
            temp_vec[y] = std::move(vec[y]); // Move existing vectors to temp_vec
        }
        temp_vec[y].resize(x_resize, Particle()); // Resize or fill new elements with default Particle values
    }

    vec = std::move(temp_vec); // Move temp_vec back to vec
}

