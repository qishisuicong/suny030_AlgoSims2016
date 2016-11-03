

#include "VectorField.hpp"



void VectorField::setup(int _w, int _h, int _d, int  _res){
    
    width = _w;
    height = _h;
    res = _res; // passing in 20, so the space between each dot is 20 pixels
    depth = _d;
    
    
    cols = width / res;
    rows = height / res;
    deps = depth / res;
    
    
    for (int z = 0; z < deps; z++) {
        vector< vector<ofVec3f> > myPlaneList;
        table.push_back ( myPlaneList );
        
        for (int y = 0; y < rows; y++) {
            vector<ofVec3f> column;
            table[z].push_back ( column );
            
            for (int x = 0; x < cols; x++) {
                ofVec3f dir(ofRandom(-10,10),ofRandom(-10,10), ofRandom(-10,10));
                table[z][y].push_back(dir);
            }
        }
    }

    
//    
//    for(int x = 0; x < cols; x++){
//        
//        vector<ofPoint> column;
//        column.resize(rows);
//        table.push_back(column);
//        
//        for(int y = 0; y < rows; y++){
//            //note that table[x] is a 1D array and table[x][y] is an ofPoint
//            table[x][y] = ofPoint(ofRandom(-10,10),ofRandom(-10,10)); //this is the vector field!
////            table[x][y] = ofPoint(5,5);
//
//        }
//    }
}

void VectorField::setNoise(float _time){
    for (int z = 0; z < table.size(); z++){
        for (int y = 0; y < table[z].size(); y++) {
            for (int x = 0; x < table[z][y].size(); x++) {
                float noise = ofMap( ofNoise(x*0.05, y*0.05,z*0.05, _time*0.1), 0, 1, 0, TWO_PI);
//            table[x][y][z].set( ofVec3f(cos(noise), sin(noise),sin(noise) )); 
            table[z][y][x].set( ofVec3f( cos(noise), sin(noise), sin (noise)) );
        }
    }
}
}

void VectorField::draw(){
    for(int z = 0; z< table.size(); z++){
        for (int y = 0; y < table[z].size(); y++) {
            for (int x = 0; x < table[z][y].size(); x++) {
            ofPushMatrix();
            ofTranslate(x*res, y*res, z*res);
                ofDrawLine(ofPoint(0,0,0), table[z][y][x]);
            ofPopMatrix();
            }
        }
    }
}


//////////////////////////////////////

//getForce will return an ofPoint. Returns a force vector
ofPoint VectorField::getForce(ofVec3f _pos){
    _pos /= res;

    
    //in the real world a vector field is defined for all points. So you could pass in 1.5, 1.5, but because table[x][y] can only be indexed by integers, we need to convert the x,y into integers.
    //if cols is 10, then table has 10 vectors. so size 10, then the valid indexes are 0 to 9.
    int x = ofClamp(int(_pos.x),0, cols-1);
    int y = ofClamp(int(_pos.y),0, rows-1);
    int z = ofClamp(int(_pos.z),0, deps-1);
//    int x = ofClamp( pctX * cols, 0, cols-1 );
//    int y = ofClamp( pctY * rows, 0, rows-1 );
//    int z = ofClamp( pctZ * deps, 0, deps-1 );
    ofVec3f newPos;
    newPos.set(table[z][y][x]);
    
    return newPos;
}

//This is decreasing the force of the vecotr field by 1%
void VectorField::update(){
for (int z = 0; z < table.size(); z++) {
    for (int y = 0; y < table[z].size(); y++) {
        for (int x = 0; x < table[z][y].size(); x++) {
            table[z][y][x] *= 0.99;
        }
    }
}
}










