#pragma once

#include "ofMain.h"
#include "Path.hpp"
#include "Vehicle.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofMesh				mesh,mesh2;
    int titleCount ;
    int zScale ;
    
    int noiseXRange;
    int noiseYRange;
    
    float noiseOffset;

    
    ofEasyCam cam;
    vector<Vehicle> fish;
    vector<Path> path;
    ofVec2f start, end;
    

    
};