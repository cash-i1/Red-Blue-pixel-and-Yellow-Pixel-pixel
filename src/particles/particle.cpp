#include "particle.h"
#include <iostream>
#include <raylib.h>
#include "../globals.h"

Particle::Particle() {};

void Particle::draw() {
    std::cout << "SDF" << std::endl;
    DrawRectangle(pos.x, pos.y, cell_size, cell_size, col);
}
