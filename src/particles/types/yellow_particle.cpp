#include "yellow_particle.h"
#include "../../globals.h"
#include <iostream>

void YellowParticle::step() {
    std::cout << "working\n"; 
    pos.y -= 10;
}
