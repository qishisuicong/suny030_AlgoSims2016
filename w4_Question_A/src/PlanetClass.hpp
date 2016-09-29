//
//  PlanetClass.hpp
//  w4_Question_A
//
//  Created by YiqiSun on 16/9/29.
//
//

#pragma once
#include "ofMain.h"

class PlanetClass{
public:
    void setup();
    void update();
    void draw();
    
    ofParameterGroup planetGroup;
    ofParameter<float> rotateSpeed;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    float rotation = 0.0;
    ofImage sun;
    ofImage earth;
    ofImage work;
};