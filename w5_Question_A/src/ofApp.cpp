#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
    
    for (int i = 0; i<5; i++) {
        Spring tempspring;
    
        tempspring.setup();
        springs.push_back(tempspring);
        springs[i].ballpos(i*ofGetWidth()/2, i*ofGetHeight()/2);
    }
//    ball.setup();
//    ball.ballpos(float x, float y);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i<springs.size(); i++) {
        springs[i].update();
//        springs[i].ballpos(i*ofGetWidth()/2, i*ofGetHeight()/2);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0 ; i<springs.size(); i++) {
        springs[i].draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
