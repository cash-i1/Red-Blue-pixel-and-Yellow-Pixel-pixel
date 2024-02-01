#include "red_particle.h"
#include "../../globals.h"

void RedParticle::step() {
    pos.y -= 1 * cell_size;
}
