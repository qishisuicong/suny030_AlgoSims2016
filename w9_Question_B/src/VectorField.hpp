

#pragma once

#include "ofMain.h"

class VectorField {
public:
        
    void setup(int _w, int _h, int  _res);
    void setNoise(float _time = 1.0);
    ofPoint getForce(ofPoint _pos);
    
    void update();
    void draw();
    ofParameterGroup vectorGroup;
    ofParameter<float> p;
    vector< vector<ofPoint> > table;
    
    int width, height, cols, rows, res;
};
