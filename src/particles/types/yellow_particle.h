#include "../particle.h"
#include <raylib.h>

class YellowParticle : public Particle {
public:
    YellowParticle() {
        
        col = YELLOW;
        type = YELLOW_P;
    }

    void step();
};
