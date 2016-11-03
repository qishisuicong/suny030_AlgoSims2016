//
//  Ball.hpp
//  w9_Question_A
//
//  Created by YiqiSun on 2016/11/2.
//
//

#pragma once
#include "ofMain.h"

class Ball{
public:
    //    Ball();
    void setup();
    void update(int count);
    void draw();
    ofPoint pos;
    ofColor color;
};