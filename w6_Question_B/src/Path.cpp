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
    start.set(0,ofGetHeight()*0.5);
    end.set(ofGetWidth(), start.y*1.2);
}

// Draw the path
void Path::draw() {
    ofSetColor(150,115,213,80);
    ofBeginShape();
    ofVertex(start.x, start.y-radius);
    ofVertex(end.x, end.y-radius);
    ofVertex(end.x, end.y+radius);
    ofVertex(start.x, start.y + radius);
    ofEndShape(true);
    
    ofSetColor(150,115,213,50);
    ofDrawLine(start.x,start.y,end.x,end.y);
}