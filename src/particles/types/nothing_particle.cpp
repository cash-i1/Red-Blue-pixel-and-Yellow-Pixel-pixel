#include "nothing_particle.h"
#include "../../globals.h"
#include <iostream>

void NothingParticle::step() {
    std::cout << "working\n"; 
    pos.y -= 10;
}
