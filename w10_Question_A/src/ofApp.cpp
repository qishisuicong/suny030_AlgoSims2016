#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    SphereRadius = 250.0;
    gridWidth = 200;
    gridHeight = 200;
    int scale = 6;
    
    //make a grid of connected lines
    //which are reallly this notion of vertices
    for(int y = 0; y<gridWidth; y++){
        for(int x = 0; x< gridHeight; x++){
            latitude.push_back( ofMap(x, 0, gridWidth, 0, (2*PI) ) );
            longitude.push_back( ofMap(y, 0, gridHeight, 0, PI ) );
            //create our mesh
//            mesh.addVertex(ofPoint((x-gridWidth*0.5)*scale,(y-gridHeight*0.5)*scale,0));
//            mesh.addColor(ofColor(0,0,0));
        }
    }
    for (unsigned i = 0; i<longitude.size(); i++) {
        float longTMP = longitude[i];
        float latTMP = latitude[i];
        float X = ( SphereRadius * cos(latTMP) * sin(longTMP) );
        float Y = ( SphereRadius * sin(latTMP) * sin(longTMP) );
        float Z = ( SphereRadius * cos(longTMP) );
        ofVec3f temp = ofVec3f(X,Y,Z);
        mesh.addVertex(temp);
        mesh.addColor(ofColor(0));
    }
    //create triangle indices
    for(int y = 0; y<gridWidth; y++){
        for(int x = 0; x<gridHeight; x++){
            i1 = x+gridWidth*y;
            i2 = x+1 +gridWidth*y;
            i3 = x+gridWidth*(y+1);
            i4 = (x+1)+gridWidth*(y+1);
            mesh.addTriangle(i1,i2,i3);
            mesh.addTriangle(i2,i3,i4);
            
            
        }
    }


}

//--------------------------------------------------------------
void ofApp::update(){

    float time = ofGetElapsedTimef();
    for(int y = 0; y<gridWidth; y++){
        for(int x = 0; x< gridHeight; x++){
            int i = x+gridWidth*y;
            ofPoint p = mesh.getVertex(i);
            float perlin = ofNoise(x*0.05, y*0.05,time*0.5);
//            SphereRadius = perlin*100;
            p.z = perlin*100;
            mesh.setVertex(i,p);
            mesh.setColor(i,ofColor(perlin*268,perlin*200, 210));
        }
    }
    
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

    
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
