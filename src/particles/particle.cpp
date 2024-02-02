#include "particle.h"
#include <iostream>
#include <raylib.h>
#include "../globals.h"

void Particle::draw() {
    // std::cout << "drawing at " << pos.y << "\n";
    DrawRectangle(pos.x * cell_size, pos.y * cell_size, cell_size, cell_size, col);
}

void Particle::step() {
    switch (type) {
        case RED_P:
            pos.y -= 0.001;
            break;
        case BLUE_P:
            pos.y -= 0.0001;
            break;
        case YELLOW_P:
            pos.x += 0.00001;
            break;
        default:
            break;
    }
}
