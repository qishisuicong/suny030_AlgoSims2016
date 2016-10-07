#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    spring1.setup();
    spring2.setup();
    spring3.setup();
    springsGroups.add(spring1.springsGroup);
    springsGroups.add(spring2.springsGroup);
    springsGroups.add(spring3.springsGroup);
    gui.setup(springsGroups);
    
//    ball.setup();
//    ball.ballpos(float x, float y);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    spring1.update();
    spring2.update();
    spring3.update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    spring1.draw();
    spring2.draw();
    spring3.draw();
    
   

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
