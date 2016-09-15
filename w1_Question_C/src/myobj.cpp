//
//  myobj.cpp
//  w01_h01_Problem_A
//
//  Created by YiqiSun on 16/9/1.
//
//

#include "myobj.hpp"
void myobj::setSrc(float _x, float _y){
    src.set(_x, _y);
}
void myobj::setDst(float _x, float _y){
    dst.set(_x, _y);
}

void myobj::powUpdatePct(float _pct,float _shaper){
    float Powpct = powf(_pct, _shaper);
    pos = dst * Powpct + src * (1.0 - Powpct);
    
    cout<<  pos.x  <<endl;
    
    //println(pos.x)
}

void myobj::draw(){
 ofSetColor(255,0,0);
    ofDrawLine(src,dst);
    
    //ofSetColor(r,g,b,a);
    
    float mappedVal = ofMap(pos.x, 400, 800, 0, 255);
    
    ofSetColor(mappedVal,pos.y/4,pos.z,200);
    ofDrawCircle(pos,10);
}