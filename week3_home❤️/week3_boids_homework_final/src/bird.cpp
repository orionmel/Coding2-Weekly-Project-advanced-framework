
#include "bird.hpp"




void Bird::draw()
{
    
//    light.setPosition(200,100,100);
//    light.enable();
//    ofSetColor(ofRandom(0, 255),130,ofRandom(35, 255));
    ofSetColor(ofRandom(100, 255),ofRandom(70, 200),200,ofRandom(20,100));
//    ofSetColor(140, 140, 140);

//    ofDrawSphere(getPosition().x, getPosition().y,getPosition().z,15);
////    🌹画圆
    ofCircle(getPosition().x, getPosition().y, 20);
    
    //🌹设置速率
    ofVec3f plusSpeed=getVelocity();
    if(getVelocity().x>0||getVelocity().y>0)
    {
        plusSpeed.x = getVelocity().x;
    }
    else if(getVelocity().x<0||getVelocity().y<0)
    {
        plusSpeed.x = getVelocity().x*0.1;
        plusSpeed.y = getVelocity().y*0.1;

    }

//    ofTriangle(getPosition().x,getPosition().y,getPosition().x+cos(60.0)*15-plusSpeed.x*2.2,getPosition().y+sin(60.0)*15-plusSpeed.y*2.2,getPosition().x+sin(60.0)*15-plusSpeed.x*2.2,getPosition().y+cos(60.0)*15-plusSpeed.y*2.2);
    
    //🌹原来的三角形
    //三角形
    //ofTriangle(position.x+velocity.x*2.2,position.y+velocity.y*2.2,position.x+cos(60.0)*15,position.y+sin(60.0)*15,position.x+sin(60.0)*15,position.y+cos(60.0)*15);
    light.disable();
}
