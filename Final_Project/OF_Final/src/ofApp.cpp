#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetFrameRate(60);
//    abc = ofGetFrameRate();
    ofSetWindowShape(2560, 1600);
    ofSetWindowPosition(0, 0);
    sea.load("sea.mp3");
    sea.play();
    
    for( int i=0; i<fishes; i++){
        myfish[i].setup(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
        myfish[i].color5 = ofColor(ofRandom(50,100));
        myfish[i].color1 = ofColor(ofRandom(165,200));
        myfish[i].color2 = ofColor(ofRandom(165,200));
        myfish[i].color3 = ofColor(ofRandom(165,200));
        myfish[i].color4 = ofColor(ofRandom(165,200));
//        myfish[i].color = ofColor(ofRandom(40,70),ofRandom(40,70),ofRandom(80,190));
        myfish[i].color = ofColor(ofRandom(180,232),ofRandom(20,80),ofRandom(0,60),ofRandom(10,40));
        
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
//    abc = ofGetFrameRate();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    ofBackground(10,30,70);
//    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for( int i=0; i<fishes; i++){
        
        myfish[i].arrive();
        myfish[i].update();
        myfish[i].draw();
        
    }
    shader.load("noise.vert","noise.frag");

    shader.begin();
    shader.setUniform1f("time", ofGetFrameNum() * 0.001);
    ofDrawRectangle(0,0,2560, 1600);
    shader.end();
//    std::cout << "framerate: " << abc << endl;
    if(time < 10){
        ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
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
