#include "../particle.h"
#include <raylib.h>

class BlueParticle : public Particle {
public:
    BlueParticle() {
        
        col = BLUE;
        type = BLUE_P;
    }

    void step();
};
