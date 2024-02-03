#pragma once

#include <raylib.h>
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
    void reinit();//
    void add_particle_at_pos(Vector2 pos, Particle p);
    void add_particle(Particle p, bool replace);
    void try_add_particle(Particle p, bool replace); // if particle exists in location, it will do notihng

    bool can_move(Particle p);
};
