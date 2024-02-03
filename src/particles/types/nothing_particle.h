#include "../particle.h"
#include <raylib.h>

class NothingParticle : public Particle {
public:
    NothingParticle() {
        
        col = Color{0,0,0,0};
        type = NOTHING_P;
    }

    void step();
};
