//
//  PlanetClass.cpp
//  w4_Question_A
//
//  Created by YiqiSun on 16/9/29.
//
//

#include "PlanetClass.hpp"

void PlanetClass::setup(){
    sun.load("sun.png");
    earth.load("earth.png");
    work.load("work.png");
    planetGroup.add(rotateSpeed.set("speed",1.0,0.0,9.0));
    planetGroup.add(posX.set("X",0,0,600));
    planetGroup.add(posY.set("Y",0,0,600));
    planetGroup.add(red.set("red",255,0,255));
    planetGroup.add(green.set("green",255,0,255));
    planetGroup.add(blue.set("blue",255,0,255));

    
}
void PlanetClass::update(){
    rotation++;

    
    
}
void PlanetClass::draw(){
//    int counter = int(ofRandom(0,3));
    ofSetColor(red,green,blue);
    ofRotate(rotation*rotateSpeed);
//    ofDrawCircle(posX, posY, 30);
    if(counter == 1){
        sun.draw(posX,posY,100,100);
    }else if(counter == 2){
        earth.draw(posX,posY,100,100);
    }else if(counter == 3){
        work.draw(posX,posY,100,100);
    }
    

}