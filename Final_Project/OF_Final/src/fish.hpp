//
//  fish.hpp
//  springsPointers
//
//  Created by YiqiSun on 11/30/16.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Spring.hpp"
#include "math.h"


class Fish{
    
public:
    void setup(int x, int y);
    void update();
    void applyForce(ofVec2f force);
    void arrive();
    void draw();
    
    
    
    
    Particle particles[5];
    Spring springs[4];
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f target;
    ofVec2f center1;
    ofVec2f point1;
    ofVec2f point2;
    ofVec2f point3;
    ofVec2f point4;
    ofVec2f point5;
    float r;
    float r2;
    float maxforce;    // Maximum steering force
    float maxspeed;    // Maximum speed
    int headingx;
    int headingy;
    int counter;
    int count;
    float anum;
    float anumcalc;
    int bodyLength;
    float x1,x2,y1,y2,ii,jj,angle1;
    ofColor color,color1,color2,color3,color4,color5;
    float outx1,outy1,outx2,outy2,theta,thet,cosalpha,l,tax1,tay1,tax2,tay2,tailx1,taily1,tailx2,taily2,ll;
};

