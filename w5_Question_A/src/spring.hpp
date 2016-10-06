//
//  spring.hpp
//  w5_Question_B
//
//  Created by YiqiSun on 2016/10/6.
//
//

#pragma once

#include "ofMain.h"
class Spring{
    
public:
    void setup();
    void update();
    void draw();
    void ballpos(float x, float y);
    
    void applyForce(ofVec2f force);
    float k;
    float restLength;
    
    ofVec2f acc, vel;
    ofVec2f anchor, ball;
    
    
    
    
    
};