//
//  spring.cpp
//  w5_Question_B
//
//  Created by YiqiSun on 2016/10/6.
//
//

#include "spring.hpp"

void Spring::setup(){
    ofBackground(0);
    springsGroup.add(k.set("Speed",0.05,0,2));
//    k = 0.05;
    springsGroup.add(restLength.set("Length",500,0,500));
//    restLength = 200;
    
    anchor = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    
   
}
void Spring::ballpos(float x, float y){
    ball.set(x, y);
}
void Spring::applyForce(ofVec2f force){
    //    acc += force;
    acc.x += force.x;
    acc.y += force.y;
}

void Spring::update(){
    
    //Steps to create the springy effect
    ofVec2f force = ball - anchor; // the direction of the vector
    
    float currentLength = force.length();
    float x = currentLength - restLength;
    //normalize refers to vector math whereby you multiply the vector by the "unit vector"
    force.normalize();
    force *= -1 * k * x;  //applying Hooke's Law
    
    applyForce(force);
    applyForce(ofVec2f(0,1.0));//brings the x component back to 0
    
    //Add dynamic movement
    vel+=acc;
    vel*=0.98; // gravity
    ball+=vel;
    acc*=0; //set back to 0 to bring the spring thing back to a neutral position.
}

void Spring::draw(){
    
    ofDrawLine(anchor, ball);
    ofDrawCircle(anchor, 10);
    ofDrawCircle(ball, 20);
    
    
    
}