//
//  Particle.cpp
//  FireWorks
//
//  Created by YiqiSun on 16/9/15.
//
//

#include "Particle.hpp"

void Particle::setup(){
    pos.x = ofGetWidth()/2;
    pos.y = 50;
    radius = 3.5;
    vel.x = ofRandom(-1,1);
    vel.y = ofRandom(-2,0);
    color = ofColor(ofRandom(150,210),0,0,50);
    someNumber = ofRandom(2, 400);
}
void Particle::explosion(){
    pos-=vel;
}
void Particle::draw(){
    ofSetColor(color);
    ofDrawEllipse(pos.x, pos.y, radius, radius);
}

void Particle::restart(){
    pos.x = ofGetWidth()/2;
    pos.y = 50;
}