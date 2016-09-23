//
//  Particle.hpp
//  FireWorks
//
//  Created by YiqiSun on 16/9/15.
//
//

#pragma once

#include "ofMain.h"


class Particle{
public:
    void draw();
    void setup();
    void explosion();
    void restart();
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    float radius;
    int someNumber;

    
};
