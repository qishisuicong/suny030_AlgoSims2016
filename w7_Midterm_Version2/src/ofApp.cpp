#include "ofApp.h"

void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(165,222,228);


    titleCount=350;
    zScale=40;
    noiseXRange=6;
    noiseYRange=6;
    noiseOffset=1;
    
    for (int i = 0; i<20;i++){
        ofPoint tempdest;
        dest.push_back(tempdest);
        
        dest[i]=ofPoint(ofRandomWidth(), ofRandomHeight() );
        Particle tempcar;
        tempcar.setInit(ofGetWindowSize()/2,ofPoint(10, ofRandom(10)));
        fish.push_back(tempcar);
        fish[i].color = ofColor(ofRandom(160));
    
        
    }
    
    
    
    cam.setPosition(ofPoint(ofGetWidth(), ofGetHeight(), 700));
    //    cam.lookAt(ofPoint(1,1,0));`
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    mesh.setMode( OF_PRIMITIVE_LINES );
    mesh2.clear();
    mesh2.setMode( OF_PRIMITIVE_LINES );
    
    float tileSizeY = (float)ofGetHeight()/titleCount;
    float noiseStepY = (float)noiseYRange/titleCount;
    float time=ofGetElapsedTimef();
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {
        
        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = 2*ofNoise(noiseX+noiseOffset, noiseY,time);
            float y1 = 2*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time);
            
            ofFill();
            ofSetColor(255,20);
            mesh.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,0));
            mesh.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,0));
            
        }
        
    }
    
    
    for (int meshy=0;  meshy<= titleCount; meshy++) {
        
        for (int meshx=0; meshx<=titleCount; meshx++) {
            float x=ofMap(meshx, 0, titleCount,-ofGetWidth()/2, ofGetWidth()/2);
            float y=ofMap(meshy, 0, titleCount,-ofGetHeight()/2, ofGetHeight()/2);
            
            float noiseX=ofMap(meshx, 0, titleCount, 0, noiseXRange);
            float noiseY=ofMap(meshy, 0, titleCount, 0, noiseYRange);
            
            float x1 = 1.5*ofNoise(noiseX+noiseOffset, noiseY,time+0.0001);
            float y1 = 1.5*ofNoise(noiseX+noiseOffset,noiseY+noiseStepY,time+0.0001);
            
            ofFill();
            ofSetColor(51,166,184,15);
            mesh2.addVertex(ofPoint(x+x1*zScale, y+x1*zScale,-20));
            mesh2.addVertex(ofPoint(x+y1*zScale, y+tileSizeY+y1*zScale,-20));
            
        }
        
    }
    
    noiseOffset+=0.005;
    float area = 200;
    for(int i = 0; i<fish.size();i++){
        fish[i].seek(dest[i]);
        if( fish[i].getPosition().distance( fish[i+1].getPosition() ) < area ){
            fish[i].color = ofColor(158,122,122,99);
            fish[i].addRepulsionForce( fish[i].getPosition(), area,  0.1 );
        }else{
            fish[i].color = ofColor(158,122,122,100);
        }
        fish[i].update();
        if( fish[i].getPosition().distance(dest[i]) < 5){
            dest[i] = ofPoint( ofRandomWidth(), ofRandomHeight() );
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(165,222,228);
    
    cam.begin();
    
    
    mesh.draw();
    ofPushMatrix();
    ofRotateZ(90);
    //    ofRotate(PI/3);
    mesh2.draw();
    ofPopMatrix();
    cam.end();
    
    for(int i = 0; i<fish.size();i++){
        ofSetColor( fish[i].color );
        ofDrawCircle( dest[i], 0.5 );
//        fish[i].follow(start,end);
        fish[i].draw();
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
