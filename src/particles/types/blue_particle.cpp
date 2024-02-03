#include "blue_particle.h"
#include "../../globals.h"
#include <iostream>

void BlueParticle::step() {
    std::cout << "working\n"; 
    pos.y -= 1;
}
