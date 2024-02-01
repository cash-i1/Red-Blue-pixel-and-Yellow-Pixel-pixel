#pragma once
#include <raylib.h>

class Particle {
public:
    Particle();

    Vector2 pos;
    Color col;

    void draw();
    void step();
    void leap(int frames); // Step goes forward one frame and leap goes forward a specified amount of frames
};
