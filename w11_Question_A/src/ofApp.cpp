#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0,0,0);
    ofEnableDepthTest();
    
    ofDisableArbTex();
    ofLoadImage(texture, "shader.jpg");
    shader.load("shader.vert", "shader.frag");
    
    // You can use also:
    //
    // ofPlanePrimitive(float width, float height, int columns, int rows)
    
    //  Let's contruct a flat mesh... is like a fabric... the dots are conected but with out relieve
    //
    int scale = 5;
    w = 1000/scale;
    h = 500/scale;
    for (int y = 0; y < h; y++){
        for (int x = 0; x<w; x++){
            
            //  Per pixel we set the position, normal and texCoord
            //
            float offsetX = 0;
//            float offsetY = (x%2==1)?0.5:0.0;
            float offsetY;
            if(x%2==1){
                offsetY = 0.5;
            } else{
                offsetY = 0.0;

            }
            
            mesh.addVertex(ofPoint((x+offsetX)*scale,(y+offsetY)*scale,0));
            mesh.addNormal(ofPoint(1,0,0));
            mesh.addTexCoord(ofVec2f((float)(x+offsetX)/(float)w,(float)(y+offsetY)/(float)h));
        }
    }
    
    //  Finally we set the indexes... We tell openGL how the vertex are connected in triangles (a,b,c)
    //
    for (int y = 0; y<h-1; y++){
        for (int x=0; x<w-1; x++){
            if(x%2==0){
                
                int i1 = x + w * y;
                int i2 = x+1 + w * y;
                int i3 = x + w * (y+1);
                int i4 = x+1 + w * (y+1);
                
                mesh.addIndex(i1);
                mesh.addIndex(i2);
                mesh.addIndex(i3);
                
                mesh.addIndex(i2);
                mesh.addIndex(i3);
                mesh.addIndex(i4);
            } else {
                
                int i1 = x + w * y;
                int i2 = x+1 + w * y;
                int i3 = x + w * (y+1);
                int i4 = x+1 + w * (y+1);
                
                mesh.addIndex(i1);
                mesh.addIndex(i2);
                mesh.addIndex(i4);
                
                mesh.addIndex(i1);
                mesh.addIndex(i3);
                mesh.addIndex(i4);
                
            }
            
                
//                mesh.addIndex(x+y*w);				// a
//                mesh.addIndex((x+1)+y*w);			// b
//                mesh.addIndex(x+(y+1)*w);			// d
//                
//                mesh.addIndex((x+1)+y*w);			// b
//                mesh.addIndex((x+1)+(y+1)*w);		// c
//                mesh.addIndex(x+(y+1)*w);			// d
//            } else {
//                mesh.addIndex((x+1)+y*w);			// b
//                mesh.addIndex(x+y*w);				// a
//                mesh.addIndex((x+1)+(y+1)*w);		// c
//                
//                mesh.addIndex(x+y*w);				// a
//                mesh.addIndex(x+(y+1)*w);			// d
//                mesh.addIndex((x+1)+(y+1)*w);		// c
//            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    for(int y = 0; y<w-1; y++){
        for(int x = 0; x<h-1; x++){
            int i = x +w*y;
            int j = x+500+w*y;
            
            ofPoint p = mesh.getVertex(i);
            ofPoint q = mesh.getVertex(j);
                
            float perlin = ofNoise(x*0.05, y*0.05, time *0.5);
            p.z = perlin * 70;
            q.z = perlin * 70;
            
            mesh.setVertex(i, p);
            mesh.setVertex(j, q);
                
            }
        }
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();
    
    //  Center the mesh;
    //
    ofTranslate(-500, -250);
    
    shader.begin();
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniformTexture("u_tex0", texture, 0);
    shader.setUniform2f("u_tex0Resolution", texture.getWidth(), texture.getHeight());
    
    mesh.drawWireframe();
//    mesh.draw();
    
    ofPopMatrix();
    shader.end();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
