

#include "Particles.h"


Particle::Particle(){
    
    radius = 1;

}

void Particle::init(){
    pos = ofPoint(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2));

    vel = ofPoint(ofRandom(-1, 1), ofRandom(-1, 1));
    
}

void Particle::bounding(){
    if(pos.y > ofGetHeight()/2 || pos.y < -ofGetHeight()/2){
        vel = -vel;
    }
    if(pos.x > ofGetWidth()/2 || pos.x < -ofGetWidth()/2){
        vel = -vel;
    }
}

void Particle::draw(){
    
        ofDrawCircle(pos.x, pos.y, pos.z, radius);


}



ofPoint Particle::cohesion(vector<Particle> &particles){

    ofPoint centerMass;
    for(int i = 0; i < particles.size(); i++){

        if (&particles[i] == this) {
            continue;
        }
        
        centerMass += particles[i].pos;
    
    }
    
    centerMass = centerMass/(particles.size()-1);
    
    ofPoint cohesion_velocity;
    cohesion_velocity = (centerMass-pos)/100.0f;
    return cohesion_velocity;
}

ofPoint Particle::separation(vector<Particle> &particles){

    
    ofPoint displace;
    for(int i = 0; i < particles.size(); i++){
  
        if (&particles[i] == this) {
            continue;
        }
        
        // distance between me and particles[i]
        float dist = pow(particles[i].pos.x - pos.x, 2) + pow(particles[i].pos.y - pos.y, 2);
        dist = sqrt(dist);

        if (dist < 10.0) {
            displace  = displace - (particles[i].pos - pos);
        }
        
    }
    
    ofPoint separation_velocity;
    separation_velocity = displace;
    return separation_velocity;
}

ofPoint Particle::allignment(vector<Particle> &particles){

    //RULE 3
    //match velocity
    
    ofPoint aveVel;
    for(int i = 0; i < particles.size(); i++){
        //determining if the particle in the loop is itself
        //to avoid itself
        if (&particles[i] == this) {
            continue;
        }
        
        aveVel += particles[i].vel;
        
    }
    
    aveVel = aveVel/(particles.size()-1);
    
    ofPoint allignment_velocity;
    allignment_velocity = (aveVel - vel)/8.0f;
    return allignment_velocity;
    
}

void Particle:: update( vector<Particle> &particles ){
    
    ofPoint v1 = cohesion(particles);
    ofPoint v2 = separation(particles);
    ofPoint v3 = allignment(particles);
    
    vel += v1 + v2 + v3;
    pos = pos + vel;
    
}


