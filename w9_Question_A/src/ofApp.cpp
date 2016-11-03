#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    
    
    for(int i = 0; i<25; i++){
        Ball tempball;
        tempball.setup();
        balls.push_back(tempball);
        balls[i].color = ofColor(ofRandom(200,240),ofRandom(200,240),ofRandom(200,240));
        
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i<25; i++){
        balls[i].update(i*100);
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<25; i++){
        ofSetColor( balls[i].color );
            balls[i].draw();
        if(i > 0){
            ofSetLineWidth(1.5);
            ofDrawLine(balls[i].pos,balls[i-1].pos);
            
        }
        
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
