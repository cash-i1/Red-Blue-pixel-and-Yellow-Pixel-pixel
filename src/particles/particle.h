#pragma once
#include <cstdlib>
#include <raylib.h>

class Particle {
public:
    Color col; 

    Particle() {
        col = Color{0, 0, 0, 0};
        id = rand();
    } // it doesnt work when i do it here
    
    enum Type {
        NOTHING_P,
        RED_P,
        BLUE_P,
        YELLOW_P,
    };

    Vector2 pos;
    Type type;
    int id;

    void draw();
    void step();
    void leap(int frames); // Step goes forward one frame and leap goes forward a specified amount of frames
};
