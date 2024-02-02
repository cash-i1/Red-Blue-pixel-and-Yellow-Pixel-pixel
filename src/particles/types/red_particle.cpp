#include "red_particle.h"
#include "../../globals.h"
#include <iostream>

void RedParticle::step() {
    std::cout << "working\n"; 
    pos.y -= 1;
}
