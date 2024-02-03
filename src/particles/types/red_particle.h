#include "../particle.h"
#include <raylib.h>

class RedParticle : public Particle {
public:
    RedParticle() {
        
        col = RED;
        type = RED_P;
    }

    void step();
};
