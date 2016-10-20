#include "Vehicle.hpp"

void Vehicle::setup(ofVec2f p, float ms, float mf) {
    yu.load("yu.png");
    pos = p;
    r = 4.0;
    maxSpeed = ms;
    maxForce = mf;
    acc.set(0, 0);
    vel.set(maxSpeed, 0);
    
  
}

void Vehicle::update() {
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
    if (pos.x < -r) pos.x = ofGetWidth()+r;
    if (pos.x > ofGetWidth()+r) pos.x = -r;
    
}

void Vehicle::resetForces() {
    acc *= 0;
}

void Vehicle::applyForce(ofVec2f force) {
    acc += force;
}

void Vehicle::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2( vel.y, vel.x );
    ofRotate(ofRadToDeg(rot)+ 180);
    
//    ofSetColor(255, 0, 0);
//    ofDrawTriangle(-40, 10, -40, -10, 0, 0);
    yu.draw(0,0, 40, 20);
    
    ofPopMatrix();
    
    
//    ofPushMatrix();
//    ofTranslate( pos );
//    float rotAmt = atan2( vel.y, vel.x );
//    ofRotate( ofRadToDeg(rotAmt) + ofRandom(175, 185) );
//
//    yu.draw(0,0, 40, 20);
//    
//    ofPopMatrix();
    
}

void Vehicle::seek(ofVec2f target) {
    ofVec2f desired = target - pos;
    
    float d = desired.length();
    desired.normalize();
    
    if (d == 0) return;
    
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= maxSpeed;
    
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
}

void Vehicle::follow(Path p) {
    
    // Predict location 25 (arbitrary choice) frames ahead
    ofVec2f predict = vel;
    predict.normalize();
    predict *= 25;
    ofVec2f predictLoc = pos + predict;
    
    // Look at the line segment
    ofVec2f a = p.start;
    ofVec2f b = p.end;
    
    // Get the normal point to that line
    ofVec2f normalPoint = getNormalPoint(predictLoc, a, b);
    
       ofVec2f dir = b - a;
    dir.normalize();
    dir *= 10;
    ofVec2f target = normalPoint + dir;

    float distance = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
    
    if (distance > p.radius) {
        seek(target);
    }
}

ofVec2f Vehicle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b) {
    ofVec2f ap = p - a;
    // Vector from a to b
    ofVec2f ab = b - a;
    ab.normalize(); // Normalize the line
       ab *= (ap.dot(ab));
    ofVec2f normalPoint = a + ab;
    return normalPoint;
}
