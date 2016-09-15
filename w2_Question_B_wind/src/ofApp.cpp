#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    a = 0;
    b = 0;
    velocity = 0.15;
    angle = 0;

    
    

}

//--------------------------------------------------------------
void ofApp::update(){
  


}

//--------------------------------------------------------------
void ofApp::draw(){
    //https://www.youtube.com/watch?v=uTlwzsud-zg The video of wind blowing
    angle += ofNoise(ofGetFrameNum());
    
    ofSetColor(255, 0, 0,70);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4, ofGetHeight()/2);
    ofRotate(angle, sin(angle), 0, 0);
    ofDrawRectangle(0, 0, 100, 100);
    ofPopMatrix();
    
    
    ofSetColor(0, 255, 0,70);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4*2, ofGetHeight()/2);
    ofRotate(angle, sin(angle), 0, 0);
    ofDrawRectangle(0, 0, 100, 100);
    ofPopMatrix();
    
    
    ofSetColor(0, 0, 255,50);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/4*3, ofGetHeight()/2);
    ofRotate(angle, sin(angle), 0, 0);
    ofDrawRectangle(0, 0, 100, 100);
    ofPopMatrix();

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
