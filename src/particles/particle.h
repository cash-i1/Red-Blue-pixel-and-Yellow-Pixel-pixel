#pragma once
#include <raylib.h>

class Particle {
public:
    Particle() : col(Color{0, 0, 0, 0}) {} // it doesnt work when i do it here

    Vector2 pos;
    Color col; // I want this to default to 0,0,0,0

    void draw();
    virtual void step();
    void leap(int frames); // Step goes forward one frame and leap goes forward a specified amount of frames
};
