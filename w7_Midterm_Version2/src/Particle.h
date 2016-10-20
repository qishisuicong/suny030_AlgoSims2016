#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    ofPoint getPosition();
    float   getRadius();
    
    void addForce(ofPoint _force);
    
    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    
    void seek( ofPoint dest );
    void follow(ofVec2f start,ofVec2f end);
    ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);
    void update();
    void draw();
    
    ofColor color;
    ofImage yu;
    
private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float radius;
    float damp;
};