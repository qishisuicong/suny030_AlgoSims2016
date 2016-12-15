//
//  fish.cpp
//  springsPointers
//
//  Created by YiqiSun on 11/30/16.
//
//

#include "fish.hpp"

void Fish::setup(int x, int y){
    head.load("head.png");
    body1.load("body1.png");
    body2.load("body2.png");
    body3.load("body3.png");
    tail1.load("tail1.png");
    tail2.load("tail2.png");
    float time = ofGetElapsedTimef();
    acceleration = ofVec2f(10, 10);
    velocity = ofVec2f(0, 0);
    location = ofVec2f(x, y);
    target = ofVec2f(headingx, headingy);
    r2 = 2;
    maxspeed = 1;
    maxforce = 0.02;
    count = int(ofRandom(200));
    bodyLength = int(ofRandom(5, 20));
//    ofBackground(0);
    float perlin = ofNoise(x*0.05, y*0.05,time*0.5);
    
    for(int i =0; i < 3; i++){
//        
//        particles[i].setInit(ofPoint(ofRandom(ofGetWidth()),
//                                     ofRandom(ofGetHeight())));
        particles[i].setInit(ofPoint(ofGetWindowWidth()*perlin*100,
                                     ofGetWindowHeight()*perlin*100));

    }
    
    particles[0].bFix = true;
    
    //spring array
    springs[0].set(&particles[0], &particles[1]);
    springs[0].restDist = 20;
    springs[1].set(&particles[1], &particles[2]);
    springs[1].restDist = 20;
    springs[2].set(&particles[2], &particles[3]);
    springs[2].restDist = 20;
    springs[3].set(&particles[3], &particles[4]);
    springs[3].restDist = 20;
    springs[4].set(&particles[4], &particles[5]);
    springs[4].restDist = 20;
    
}


//--------------------------------------------------------------
void Fish::update(){
    // Update velocity
    velocity+=acceleration;
    // Limit speed
    velocity.limit(maxspeed);
    location+=velocity;
    // Reset accelerationelertion to 0 each cycle
    acceleration*=0;
    if (counter >= count) {
        counter = 0;
        
        //changing this line changes the tendency to change heading.  I highly recommend perlin noise here.
        count = int(ofRandom(200));
        
        
        headingx = int(ofRandom(ofGetWindowWidth()));
        headingy = int(ofRandom(ofGetWindowHeight()));
    }
    target.x = headingx;
    target.y = headingy;
    
    counter++;
    ofPoint p;
    p.x=location.x + (((bodyLength))-abs(ofDist(0,0,velocity.x,velocity.y)))*(sin(anum)*velocity.y);
    p.y=location.y + (((bodyLength))-abs(ofDist(0,0,velocity.x,velocity.y)))*((-1*sin(anum))*velocity.x); //+ .1*(1-sin(anum)*target.x);
    
    
    
    r = r2*(ofMap(bodyLength, 5, 20, .5, 3));

//    ofPoint p = ofPoint(_x,_y);
    particles[0].pos.set(p);
    
    for(int i =0; i< 4; i++){
        springs[i].update();
    }
    
    for(int i = 0; i < 5; i++){
        particles[i].addForce(ofPoint(0,0.1));
        particles[i].update();
//        particles[i].bounding();
    }
    
}
void Fish::applyForce(ofVec2f force) {
    // We could add mass here if we want A = F / M
    acceleration+=force;
}

// A method that calculates a steering force towards a target
void Fish::arrive() {
    ofVec2f desired = ofVec2f(target - location);  // A vector pointing from the location to the target
    float d = ofDist(0,0,desired.x,desired.y);
    if (d < 100) {
        float m = ofMap(d, 0, 100, 0, maxspeed);
//        desired.setMag(m);
        desired = desired.normalize() * m;
    } else {
//        desired.setMag(maxspeed);
        desired = desired.normalize() * maxspeed;
    }
    
    //changing the properties of this line changes the overal vigor and speed of swimming, before scale
    ofVec2f j = ofVec2f(desired.x * desired.x + desired.y * desired.y);
    float k = ofDist(0,0,j.x,j.y);
    anumcalc = .06*(k*(20/bodyLength));
    anum+=anumcalc;
    ofVec2f steer = ofVec2f(desired - velocity);
    steer.limit(maxforce);  // Limit to maximum steering force
    applyForce(steer);
}





//--------------------------------------------------------------
void Fish::draw(){
//    ofPushMatrix();
//    ofTranslate(pos);
//    float rot = atan2( vel.y, vel.x );
//    ofRotate(ofRadToDeg(rot)+ 180);
//    yu.draw(0,0, 40, 20);
//    
//    ofPopMatrix();
    
    for(int i =0; i< 4; i++){
//        springs[i].draw();
        
        

    }
    
    for(int i = 0; i < 5; i++){
        
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
        l = sqrt(((particles[1].pos.y-particles[0].pos.y)*(particles[1].pos.y-particles[0].pos.y))+((particles[0].pos.x-particles[1].pos.x))*(particles[0].pos.x-particles[1].pos.x));
        cosalpha = abs(particles[1].pos.x-particles[0].pos.x)/l;
        theta = 45-acos(cosalpha);
        thet = acos(cosalpha)-45;
        
        ////////////////////////////////////////////////
        
        if(particles[1].pos.x > particles[0].pos.x & particles[1].pos.y >= particles[0].pos.y){
        outx1 = particles[0].pos.x+cos(90-theta)* sqrt(2)/2*l;
        outy1 =particles[0].pos.y+cos(theta)*sqrt(2)/2*l;
        outx2 = particles[0].pos.x+cos(theta)*sqrt(2)/2*l;
        outy2 = particles[0].pos.y-cos(90-theta)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////////
        
        if(particles[0].pos.x > particles[1].pos.x & particles[0].pos.y >= particles[1].pos.y){
            outx1 = particles[0].pos.x-cos(90-theta)* sqrt(2)/2*l;
            outy1 =particles[0].pos.y-cos(theta)*sqrt(2)/2*l;
            outx2 = particles[0].pos.x-cos(theta)*sqrt(2)/2*l;
            outy2 = particles[0].pos.y+cos(90-theta)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////////
        
        
        if(particles[0].pos.x >= particles[1].pos.x & particles[0].pos.y < particles[1].pos.y){
            outx1 = particles[0].pos.x-cos(thet)* sqrt(2)/2*l;
            outy1 =particles[0].pos.y+cos(90-thet)*sqrt(2)/2*l;
            outx2 = particles[0].pos.x+cos(90-thet)*sqrt(2)/2*l;
            outy2 = particles[0].pos.y+cos(thet)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////
        
        if(particles[0].pos.x <= particles[1].pos.x & particles[0].pos.y > particles[1].pos.y){
            outx1 = particles[0].pos.x+cos(thet)* sqrt(2)/2*l;
            outy1 =particles[0].pos.y-cos(90-thet)*sqrt(2)/2*l;
            outx2 = particles[0].pos.x-cos(90-thet)*sqrt(2)/2*l;
            outy2 = particles[0].pos.y-cos(thet)*sqrt(2)/2*l;
        }
        
        ////////////////////////////////////////////////
        
        ofVec2f pol = ofVec2f(outx1,outy1);
        ofVec2f por = ofVec2f(outx2,outy2);

        ofVec2f eyel = (particles[0].pos+pol)/2;
        ofVec2f eyer = (particles[0].pos+por)/2;
        
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
        
        

        
//        particles[i].draw();
        ofSetColor(color);
        point1=particles[0].pos;
        x2=point1.x;
        y2=point1.y;
        point2=particles[1].pos;
        x1=point2.x;
        y1=point2.y;
        //First 4 original middle dots
        ofVec2f mid1 = (particles[0].pos+particles[1].pos)/2;
        ofVec2f mid2 = (particles[1].pos+particles[2].pos)/2;
        ofVec2f mid3 = (particles[2].pos+particles[3].pos)/2;
        ofVec2f mid4 = (particles[3].pos+particles[4].pos)/2;
        //Mid of middle dots
        ofVec2f mid5 = (particles[0].pos+mid1)/2;
        ofVec2f mid6 = (particles[1].pos+mid1)/2;
        ofVec2f mid7 = (particles[1].pos+mid2)/2;
        ofVec2f mid8 = (particles[2].pos+mid2)/2;
        ofVec2f mid9 = (particles[2].pos+mid3)/2;
        ofVec2f mid10 = (particles[3].pos+mid3)/2;
        ofVec2f mid11 = (particles[3].pos+mid4)/2;
        ofVec2f mid12 = (particles[4].pos+mid4)/2;
        
//        ii = x1-x2;
//        jj = y2-y1;
        angle1 = ii/jj;
//        ofSetColor(color);
        
        ofDrawCircle(mid5, 9.5);
        ofDrawCircle(mid1, 9);
        ofDrawCircle(mid6, 8.5);
        
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        
        
        l = sqrt(((mid2.y-mid1.y)*(mid2.y-mid1.y))+((mid1.x-mid2.x))*(mid1.x-mid2.x));
        cosalpha = abs(mid2.x-mid1.x)/l;
        theta = 45-acos(cosalpha);
        thet = acos(cosalpha)-45;
        
        ////////////////////////////////////////////////
        
        if(mid2.x > mid1.x & mid2.y >= mid1.y){
            tax1 = mid1.x+cos(90-theta)* sqrt(2)/2*l;
            tay1 = mid1.y+cos(theta)*sqrt(2)/2*l;
            tax2 = mid1.x+cos(theta)*sqrt(2)/2*l;
            tay2 = mid1.y-cos(90-theta)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////////
        
        if(mid1.x > mid2.x & mid1.y >= mid2.y){
            tax1 = mid1.x-cos(90-theta)* sqrt(2)/2*l;
            tay1 =mid1.y-cos(theta)*sqrt(2)/2*l;
            tax2 = mid1.x-cos(theta)*sqrt(2)/2*l;
            tay2 = mid1.y+cos(90-theta)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////////
        
        
        if(mid1.x >= mid2.x & mid1.y < mid2.y){
            tax1 = mid1.x-cos(thet)* sqrt(2)/2*l;
            tay1 = mid1.y+cos(90-thet)*sqrt(2)/2*l;
            tax2 = mid1.x+cos(90-thet)*sqrt(2)/2*l;
            tay2 = mid1.y+cos(thet)*sqrt(2)/2*l;
        }
        
        /////////////////////////////////////////////
        
        if(mid1.x <= mid2.x & mid1.y > mid2.y){
            tax1 = mid1.x+cos(thet)* sqrt(2)/2*l;
            tay1 = mid1.y-cos(90-thet)*sqrt(2)/2*l;
            tax2 = mid1.x-cos(90-thet)*sqrt(2)/2*l;
            tay2 = mid1.y-cos(thet)*sqrt(2)/2*l;
        }
        
        ////////////////////////////////////////////////
        
        ofVec2f poll = ofVec2f(tax1,tay1);
        ofVec2f porr = ofVec2f(tax2,tay2);
        
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        ll = sqrt(((particles[4].pos.y-mid11.y)*(particles[4].pos.y-mid11.y))+((mid11.x-particles[4].pos.x))*(mid11.x-particles[4].pos.x));
        cosalpha = abs(particles[4].pos.x-mid11.x)/l;
        theta = 45-acos(cosalpha);
        thet = acos(cosalpha)-45;
        
        ////////////////////////////////////////////////
        
        if(particles[4].pos.x > mid11.x & particles[4].pos.y >= mid11.y){
            tailx1 = mid11.x+cos(90-theta)* sqrt(2)/2*ll;
            taily1 =mid11.y+cos(theta)*sqrt(2)/2*ll;
            tailx2 = mid11.x+cos(theta)*sqrt(2)/2*ll;
            taily2 = mid11.y-cos(90-theta)*sqrt(2)/2*ll;
        }
        
        /////////////////////////////////////////////////
        
        if(mid11.x > particles[4].pos.x & mid11.y >= particles[4].pos.y){
            tailx1 = mid11.x-cos(90-theta)* sqrt(2)/2*ll;
            taily1 = mid11.y-cos(theta)*sqrt(2)/2*ll;
            tailx2 = mid11.x-cos(theta)*sqrt(2)/2*ll;
            taily2 = mid11.y+cos(90-theta)*sqrt(2)/2*ll;
        }
        
        /////////////////////////////////////////////////
        
        
        if(mid11.x >= particles[4].pos.x & mid11.y < particles[4].pos.y){
            tailx1 = mid11.x-cos(thet)* sqrt(2)/2*ll;
            taily1 = mid11.y+cos(90-thet)*sqrt(2)/2*ll;
            tailx2 = mid11.x+cos(90-thet)*sqrt(2)/2*ll;
            taily2 = mid11.y+cos(thet)*sqrt(2)/2*ll;
        }
        
        /////////////////////////////////////////////
        
        if(mid11.x <= particles[4].pos.x & mid11.y > particles[4].pos.y){
            tailx1 = mid11.x+cos(thet)* sqrt(2)/2*ll;
            taily1 = mid11.y-cos(90-thet)*sqrt(2)/2*ll;
            tailx2 = mid11.x-cos(90-thet)*sqrt(2)/2*ll;
            taily2 = mid11.y-cos(thet)*sqrt(2)/2*ll;
        }
        
        ////////////////////////////////////////////////
        
        ofVec2f polll = ofVec2f(tailx1,taily1);
        ofVec2f porrr = ofVec2f(tailx2,taily2);
        
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////

        
        
        
        
        
        
        
        
        
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////
        

        
        
        
        
        ofDrawCircle(particles[1].pos, 8);
        ofDrawCircle(mid7, 7.5);
        ofDrawCircle(mid2, 7);
        ofDrawCircle(mid8, 6.5);
        ofDrawCircle(particles[2].pos, 6);
        ofDrawCircle(mid9, 5.5);
        ofDrawCircle(mid3, 5);
        ofDrawCircle(mid10, 4.4);
        ofDrawCircle(particles[3].pos, 4);
//        ofDrawCircle(mid11, 3.5);
//        ofDrawCircle(mid4,3);
//        ofDrawCircle(mid12, 2.5);
        //tail
//        ofDrawCircle(particles[4].pos,2);
        //head
        ofDrawCircle(particles[0].pos, 10);
        //eyes
        ofSetLineWidth(10);
        //tails
        ofDrawLine(particles[0].pos,poll);
        ofDrawLine(particles[0].pos,porr);
        ofDrawLine(mid1,poll);
        ofDrawLine(mid1,porr);
        ofDrawCircle(poll,3);
        ofDrawCircle(porr,3);
        ofSetLineWidth(5);
        ofDrawLine(particles[3].pos,polll);
        ofDrawLine(particles[3].pos,porrr);
        ofDrawLine(mid11,polll);
        ofDrawLine(mid11,porrr);
        ofDrawCircle(polll,2);
        ofDrawCircle(porrr,2);
        //eyes
        ofSetColor(color5-50);
//        ofDrawCircle(particles[0].pos, 5);
        ofDrawCircle(eyel, 2.5);
        ofDrawCircle(eyer, 2.5);
        
//
        
        

//        ofTranslate(pos);
//        float rot = atan2( vel.y, vel.x );
//        ofRotate(ofRadToDeg(rot)+ 180);
        
        
//        ofPushMatrix();
//        ofTranslate(particles[4].pos);
//        float rot = atan2( velocity.y, velocity.x );
//        ofRotate(ofRadToDeg(rot)+ 180);
//        ofSetColor(color5);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        tail2.draw(0,0,
//                   60, 40);
//        ofPopMatrix();
//
//        ofPushMatrix();
//        ofTranslate(particles[4].pos);
//        ofRotate(ofRadToDeg(rot)+ 180);
//                ofSetColor(color4);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        tail1.draw(0,0,
//                   60, 60);
//        ofPopMatrix();
//        
//        ofPushMatrix();
//        ofTranslate(particles[3].pos);
//        ofRotate(ofRadToDeg(rot)+ 180);
//                ofSetColor(color3);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        body3.draw(0,0,
//                   40, 40);
//        ofPopMatrix();
//        
//        ofPushMatrix();
//        ofTranslate(particles[2].pos);
//        ofRotate(ofRadToDeg(rot)+ 180);
//                ofSetColor(color2);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        body2.draw(0,0,
//                   40, 40);
//        ofPopMatrix();
//        
//        ofPushMatrix();
//        ofTranslate(particles[1].pos);
//        ofRotate(ofRadToDeg(rot)+ 180);
//                ofSetColor(color1);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        body1.draw(0,0,
//                   40, 40);
//        ofPopMatrix();
//        
//        ofPushMatrix();
//        ofTranslate(x2,y2);
//        ofRotate(ofRadToDeg(rot)+ 180);
//        ofSetColor(color);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//        head.draw(0,0,
//                  40, 70);
//        ofSetColor(color1);
//        ofPopMatrix();





    }
}

