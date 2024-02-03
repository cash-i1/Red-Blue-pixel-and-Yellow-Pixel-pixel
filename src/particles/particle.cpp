#include "particle.h"
#include <iostream>
#include <raylib.h>
#include <string>
#include "../globals.h"

void Particle::draw() {
    // std::cout << "drawing at " << pos.y << "\n";
    DrawRectangle(pos.x * cell_size, pos.y * cell_size, cell_size, cell_size, col);
}

void Particle::step() {
    // std::string result = "Color(" + std::to_string(col.r) + ", " + std::to_string(col.g) + ", " + std::to_string(col.b) + ", " + std::to_string(col.a) + ")";

    switch (type) {
        case RED_P:
            pos.y -= 0.001;
            // std::cout << result << std::endl;
            break;
        case BLUE_P:
            pos.y -= 0.001;
            break;
        case YELLOW_P:
            pos.x += 0.01;
            break;
        default:
            break;
    }
}
