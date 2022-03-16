#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
    //🌹删除新的boids的备份
    for (int i = 0; i < birds.size(); i++)
    {
        delete birds[i];
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	
    soundloop.load("bubble.wav");
    
    soundloop.play();
    soundloop.setLoop(true);
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();
//    ofBackground(255,100,255);
	
//    ofBackground(97,78,119);
	
	// 推到boid里面
	for (int i = 0; i < 50; i++)
		boids.push_back(new Boid());
    
    //🌹设置新的boid的数量变化
    for (int i = 0; i < 80; i++)
        birds.push_back(new Bird());

}


//--------------------------------------------------------------
void testApp::update(){
    soundloop.setVolume(ofRandom(0,0.8));
  ofBackground(0,0,0);


    //改变移动的范围
    ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
 
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids,birds, min, max);
	}
    // 🌹必须更新，否则 boids 不会移动
    for (int i = 0; i < birds.size(); i++)
    {
        birds[i]->update(birds,boids, min,max);
    }
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
    // 🌹画新的boids
    for (int i = 0; i < birds.size(); i++)
    {
        birds[i]->draw();
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
