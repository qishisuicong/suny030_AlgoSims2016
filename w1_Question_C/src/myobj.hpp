//
//  myobj.hpp
//  w01_h01_Problem_A
//
//  Created by YiqiSun on 16/9/1.
//
//

#pragma once
#include"ofMain.h"

class myobj{

public:
    
    void setSrc(float _x,float _y);
    void setDst(float _x,float _y);
    
    void updatePct(float _pct);
    
    void powUpdatePct(float _pic,float _shaper);
    void draw();
    
private:
    ofPoint src, dst;
    ofPoint pos;
    
    
};