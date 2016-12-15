#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofBackground(255);
    
    
    
    for( int i=0; i<fishes; i++){
        myfish[i].setup(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
        myfish[i].color = ofColor(ofRandom(165,200));
        myfish[i].color1 = ofColor(ofRandom(165,200));
        myfish[i].color2 = ofColor(ofRandom(165,200));
        myfish[i].color3 = ofColor(ofRandom(165,200));
        myfish[i].color4 = ofColor(ofRandom(165,200));
        myfish[i].color5 = ofColor(ofRandom(165,200));
        
    }
  
    
}

//--------------------------------------------------------------
void ofApp::update(){


    
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    for( int i=0; i<fishes; i++){
        
//        fishes[i].draw();
        myfish[i].arrive();
        myfish[i].update();
        myfish[i].draw();
        
    }
    
//    for(int i =0; i< 4; i++){
//        springs[i].draw();
//    }
//    
//    for(int i = 0; i < 5; i++){
//        
//        particles[i].draw();
//    }

    
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
