#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    a = 0;
    b = 0;
    easing =0.05;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    targetX = ofGetMouseX();
    dx = targetX -a;
    a+= dx*easing;
    targetY = ofGetMouseY();
    dy = targetY -b;
    b+= dy*easing;


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofCircle(a,b,50,50);
    

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
