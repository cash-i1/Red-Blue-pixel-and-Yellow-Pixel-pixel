#pragma once
#include <raylib.h>

class Particle {
public:
    Particle() {
        col = Color{0, 0, 0, 0};
    } // it doesnt work when i do it here
    
    enum Type {
        NOTHING_P,
        RED_P,
        BLUE_P,
        YELLOW_P,
    };

    Vector2 pos;
    Color col; // I want this to default to 0,0,0,0
    Type type; 

    void draw();
    void step();
    void leap(int frames); // Step goes forward one frame and leap goes forward a specified amount of frames
};
