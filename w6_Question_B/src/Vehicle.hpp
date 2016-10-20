//
//  Vehicle.hpp
//  w6_Question_B
//
//  Created by YiqiSun on 2016/10/13.
//
//

#pragma once
#include "ofMain.h"
#include "Path.hpp"

class Vehicle {
public:
    
    void setup(ofVec2f p, float ms, float mf);
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void seek (ofVec2f target);
    void follow(Path p);
    ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);
    
    ofVec2f pos, vel, acc;
    
    float maxSpeed, maxForce;
    
    float r;
    
    
};