//
//  Particle.hpp
//  Particle
//
//  Created by YiqiSun on 16/9/15.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    void setup();
    void update();
    void draw();
    void bounding();
    ofPoint pos;
    ofPoint vel;
    float radius;
    float sine;
    float cosine;
    
};
