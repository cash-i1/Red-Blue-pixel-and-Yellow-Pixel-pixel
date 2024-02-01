#include "../particle.h"
#include <raylib.h>

class RedParticle : public Particle {
public:
    RedParticle() {
        col = RED;
    }

    void step() override;
};
