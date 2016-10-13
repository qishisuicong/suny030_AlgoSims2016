#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i<ofRandom(15);i++){
        ofPoint tempdest;
        dest.push_back(tempdest);
        dest[i]=ofPoint(ofRandomWidth(), ofRandomHeight() );
        Particle tempcar;
        tempcar.setInit(ofGetWindowSize()/2,ofPoint(10, ofRandom(10)));
        cars.push_back(tempcar);
        cars[i].color = ofColor(ofRandom(160));
        
    }
    
    ofBackground(255);
    
  
}

//--------------------------------------------------------------
void ofApp::update(){
    float area = 200;
    for(int i = 0; i<cars.size();i++){
        cars[i].seek(dest[i]);
        if( cars[i].getPosition().distance( cars[i+1].getPosition() ) < area ){
            cars[i].color = ofColor(ofRandom(255),100);
            cars[i].addRepulsionForce( cars[i].getPosition(), area,  0.1 );
        }else{
            cars[i].color = ofColor(ofRandom(255),10,10);
            }
        cars[i].update();
        if( cars[i].getPosition().distance(dest[i]) < 5){
            dest[i] = ofPoint( ofRandomWidth(), ofRandomHeight() );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    for(int i = 0; i<cars.size();i++){
        ofSetColor( cars[i].color );
        ofDrawCircle( dest[i], 4 );
        cars[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
