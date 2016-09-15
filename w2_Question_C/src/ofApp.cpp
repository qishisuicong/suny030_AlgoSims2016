#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
//    ofBackground(0);
    a = 0;
    b = 0;
    easing =0.05;
    result= 0;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    targetX = ofGetMouseX();
    dx = targetX -a;
    a+= dx*easing;
    targetY = ofGetMouseY();
    dy = targetY -b;
    b+= dy*easing;
    result= atan2 (a,b) * 180 / PI;


}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    cam.begin();
    
    ofSetColor(ofRandom( 0, 255 ),ofRandom( 0, 255 ),ofRandom( 0, 255 ) ,30);
    //    ofSetColor(255,0,0);
    ofDrawRectangle(a,b,3*result,3*result);
    
//    ofDrawBox(0, 0, 0, 50, 50, 50);
    
//    cam.end();
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
