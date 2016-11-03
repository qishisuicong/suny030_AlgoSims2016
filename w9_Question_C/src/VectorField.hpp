

#pragma once

#include "ofMain.h"

class VectorField {
public:
        
    void setup(int _w, int _h, int _d, int  _res);
    void setNoise(float _time = 1.0);
    ofPoint getForce(ofVec3f _pos);
    
    void update();
    void draw();
//    vector< vector<ofPoint> > table;
    vector < vector< vector<ofVec3f> > > table;

    
    int width, height,depth, cols, rows, res,deps;
};
