//
//  Ball.cpp
//  w9_Question_A
//
//  Created by YiqiSun on 2016/11/2.
//
//

#include "Ball.hpp"


void Ball::setup(){
    pos = ofPoint(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
    
    
}
void Ball::update(int count){
    pos.x = ofNoise(ofGetElapsedTimef()+count)*ofGetWidth();
    pos.y = ofNoise(ofGetElapsedTimef()-count)*ofGetHeight();
//      pos.x = ofRandom(ofGetWindowWidth());
//      pos.y = ofRandom(ofGetWindowHeight());

    
}

void Ball::draw(){
    ofSetCircleResolution(50);
    ofDrawCircle(pos,25);
}