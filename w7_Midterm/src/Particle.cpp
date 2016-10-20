#include "Particle.h"

Particle::Particle() {
    yu.loadImage("yu.png");
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.95; // de resistance!!!
    radius = 5;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

ofPoint Particle::getPosition(){
    return pos;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::addRepulsionForce(ofPoint _pos, float _rad, float _scale){
    
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;// PRO way
        addForce(-diff*_scale);
    }
}

void Particle::addAttractionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;
        addForce(diff*_scale);
    }
}

void Particle::seek( ofPoint dest ) {
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofPoint desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }
    
    ofPoint steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}
//void Particle::follow(ofVec2f start,ofVec2f end) {
//    
//    ofVec2f predict = vel;
//    predict.normalize();
//    predict *= 25;
//    ofVec2f predictLoc = pos + predict;
//    
//    
//    ofVec2f a = start;
//    ofVec2f b = end;
//    
//    
//    ofVec2f normalPoint = getNormalPoint(predictLoc, a, b);
//    
//    
//    ofVec2f dir = b - a;
//    dir.normalize();
//    dir *= 10;
//    ofVec2f dest = normalPoint + dir;
//    
//    float distance = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
//    
//    seek(dest);
//
//
//    
//}
//ofVec2f Particle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b) {
//    ofVec2f ap = p - a;
//    ofVec2f ab = b - a;
//    ab.normalize();
//    ab *= (ap.dot(ab));
//    ofVec2f normalPoint = a + ab;
//    return normalPoint;
//}


void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back        vel.y *= -1.0;
    }
}

void Particle::draw() {
//    ofCircle(pos, radius);
    
//    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + ofRandom(175, 185) );
//    ofRect( 0,0, 20, 40);
    yu.draw(0,0, 40, 20);
    
    ofPopMatrix();
}