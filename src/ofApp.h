#pragma once

#include "ofxGui.h"
#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{
    
public:
    
    ////////////////////////////////////////////////////////////////🌟🌟🌟🌟🌟基本🌟🌟🌟🌟🌟///////////////////////////////////////
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
    
    
    ////////////////////////////////////////////////////////////////🌟🌟🌟🌟🌟有关声音的🌟🌟🌟🌟🌟///////////////////////////////////////
    //为了画
    float waveform[4096]; //make this bigger, just in case
    int waveIndex;
    
    ofSoundStream soundStream;
    
    /* ofxMaxi*/
    void audioIn(ofSoundBuffer& input) override; // not used in this example
    void audioOut(ofSoundBuffer& output) override;
    maxiOsc myOsc1;
    maxiOsc myOsc2;
    maxiOsc myOsc3;
    maxiClock myClock;
    float myFreq = 0;
    
    
    maxiSample mySample;
    ////////////////❤️////////////////
    
    
    
    ////////////////////////////////////////////////////////////////🌟🌟🌟🌟🌟创建gui🌟🌟🌟🌟🌟///////////////////////////////////////
    ofxPanel gui;
    
   
    
    //创造vec2,3,4不同选项的滑块

    ofxVec4Slider vec4Slider;
    
    
    ////////////////////////////////⚠️⚠️⚠️⚠️隧道⚠️⚠️⚠️⚠️///////////////////////////////////
    glm::vec3 make_point(float R, float r, float u, float v);
 
    ofEasyCam cam;
    
    
};
