#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int scale = 6;
    num = 1000;
    //Arrays(vectors) initialize the arrays
    for(int i=0;i <num; i++){
        ofPoint p;//temp
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        float chph;
        changePhi.push_back(chph);
        
        float cht;
        changeTheta.push_back(cht);
        
        //make the sphere

        theta[i]=ofRandom(0,2*PI);
        phi[i]=ofRandom(0,PI);
        radius[i]=ofRandom(180,220);
        
        //ofPoint(x,y,z)
        points[i] = ofPoint(
            radius[i]*sin(phi[i])*cos(theta[i]),
            radius[i]*sin(phi[i])*sin(theta[i]),
            radius[i]*cos(phi[i])
        );
        mesh.addVertex(points[i]);
        mesh.addColor(ofColor(0,0,0));
        
        }

}

//--------------------------------------------------------------
void ofApp::update(){
//    float time = ofGetElapsedTimef();
//    for(int i=0;i <num; i++){
//
//        int k = i;
//        ofPoint p = mesh.getVertex(k);
//        float perlin = ofNoise(i*0.05, i*0.05,time*0.5);
//        p.z = perlin*200;
//   
//
//        mesh.setVertex(k,p);
//        mesh.setColor(k,ofColor(perlin*255,perlin*255, 255));
//        
//    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    ofBackground(29,144,213);
    
    cam.begin();

    for(int i=0; i<num;i++){
        points[i] = ofPoint(
                            radius[i]*sin(phi[i])*cos(theta[i]),
                            radius[i]*sin(phi[i])*sin(theta[i]),
                            radius[i]*cos(phi[i])
                            );
        theta[i] += changeTheta[i];
        phi[i] += changePhi[i];
        if(radius[i]<300){
            radius[i]++;
        }
    
    }
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            ofSetColor(255,50);
            dist = pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2)+pow(points[i].z-points[j].z, 2);
            
            //            dis = sqrt(dist);
            
            if(dist<2000){
//                ofDrawLine(points[i].x, points[i].y, points[i].z, points[j].x, points[j].y, points[j].z);
                mesh2.addVertex(points[i]);
    

                
            };
        };
    }
    mesh.drawWireframe();
    
    
    cam.end();
    

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
