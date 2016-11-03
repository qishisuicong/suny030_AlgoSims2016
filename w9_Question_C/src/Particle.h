#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    float   getRadius();
    ofPoint getPosition();
    ofPoint getVelocity();
    
    void addForce(ofPoint _force);
//    void mouse(int x, int y);
    
    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    void addFlockingForce(vector<Particle> &_particles, float _neighborhoodRadius, float _alignmentScale = 0.33, float _separationScale = 0.33, float _cohesionScale = 0.33);
    
    void bounding();
    void infiniteWalls();
    
    void update();
    void draw();
    ofVec2f mAcc;
    
private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    vector<ofPoint> tail;
    
    float radius;
    float damp;
};