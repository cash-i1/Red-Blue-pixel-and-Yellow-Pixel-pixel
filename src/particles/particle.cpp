#include "particle.h"
#include <iostream>
#include <raylib.h>
#include "../globals.h"

void Particle::draw() {
    DrawRectangle(pos.x * cell_size, pos.y * cell_size, cell_size, cell_size, col);
}
