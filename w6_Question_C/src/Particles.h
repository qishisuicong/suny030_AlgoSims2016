
#pragma once
#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void init();
    void bounding();
    void draw();

    void update( vector<Particle> &particles );

    ofPoint cohesion(vector<Particle> &particles);
    ofPoint separation(vector<Particle> &particles);
    ofPoint allignment(vector<Particle> &particles);
    ofPoint tend_to_place(vector<Particle> &particles);
    
    ofPoint pos;
    ofPoint vel;
    int radius;
    

};