#pragma once

#include <vector>
#include "../particles/particle.h"
#include "../globals.h"

class Grid {
public:
    Grid();
    
    std::vector<std::vector<Particle>> vec;

    void draw();
    void step();
    void leap(int frames); // Step goes forward one frame and leap goes forward a specified amount of frames
    void init();
};
