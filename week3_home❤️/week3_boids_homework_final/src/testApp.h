#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"
#include "bird.hpp"
//里面包含了bird和boid的头部文件

class testApp : public ofBaseApp{
	
public:
    ~testApp();
	
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
    
    //boid* 表示父级
    //boids表示声明，占位符的作用
    std::vector<Boid *> boids;
    //🌹声明第二个动态向量数组，bird有boid的大部分属性
    std::vector<Boid *> birds;
    
    //创建audio
    ofSoundPlayer soundloop;
};

#endif	
