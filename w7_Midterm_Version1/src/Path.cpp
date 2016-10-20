//
//  Path.cpp
//  w6_Question_B
//
//  Created by YiqiSun on 2016/10/13.
//
//

#include "Path.hpp"


Path::Path() {
    // Arbitrary radius of 20
    radius = 20;
//    start.set(ofRandom(ofGetWidth()),ofGetHeight()*0.5);
//    end.set(ofGetWidth(), ofGetHeight());
}
void Path::setInit(class ofVec2f _start,class ofVec2f _end){
    start.set(_start);
    end.set( _end);
}

// Draw the path
void Path::draw() {
//    ofSetColor(0,100);
//    ofBeginShape();
//    ofVertex(start.x, start.y-radius);
//    ofVertex(end.x, end.y-radius);
//    ofVertex(end.x, end.y+radius);
//    ofVertex(start.x, start.y + radius);
//    ofEndShape(true);
//    
//    ofSetColor(0);
//    ofDrawLine(start.x,start.y,end.x,end.y);
}