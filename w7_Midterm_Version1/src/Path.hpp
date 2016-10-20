//
//  Path.hpp
//  w6_Question_B
//
//  Created by YiqiSun on 2016/10/13.
//
//

#pragma once
#include "ofMain.h"

class Path {
public:
    
    Path();
    void draw();
    void setInit(ofVec2f _start, ofVec2f _end);
    
    ofVec2f start, end;
    float radius;
    
    
};