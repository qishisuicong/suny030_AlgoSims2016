//
//  MyBall.hpp
//  Myball
//
//  Created by YiqiSun on 16/9/8.
//
//

#pragma once

#include "ofMain.h"
class MyBall{
    public:
    MyBall();
    void update();
    void draw();
    
    ofPoint position;
    ofVec2f velocity;
};
