//
//  Particle.cpp
//  Particle
//
//  Created by YiqiSun on 16/9/15.
//
//

#include "Particle.hpp"

Particle::Particle(){
    radius = 1.5;
    sine = sin(ofGetElapsedTimef()*2.0)*2;
    cosine = cos(ofGetElapsedTimef()*2.0)*2;
}

void Particle::setup(){
    pos = ofPoint(0,0,0);
    vel = ofPoint(ofRandom(sine,cosine),ofRandom(-1,1),ofRandom(-1,1));
    
}

void Particle::draw(){
    ofDrawCircle(pos.x,pos.y,pos.z,radius);
}

void Particle::update(){
    pos=pos+vel;
//    pos.x = pos.x + radius * cos (100);
//    pos.y = pos.y + radius * cos (100);
}
void Particle::bounding(){
    if(pos.y>200 || pos.y<-200){
        vel.y = -vel.y;
    }
    if(pos.x>200 || pos.x<-200){
        vel.x = -vel.x;
    }
    if(pos.z>200 || pos.z<-200){
        vel.z = -vel.z;
    }
}
