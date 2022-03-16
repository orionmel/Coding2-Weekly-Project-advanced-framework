

#include "boid.h"
#include "ofMain.h"


Boid::Boid()
{
    separationWeight = 0.9f;
    cohesionWeight = 0.3f;
    alignmentWeight = 0.2f;
    
    separationThreshold = 100;
    neighbourhoodSize = 100;
    
    //设置开始的位置
    position = ofVec3f(ofRandom(-10, 20), ofRandom(-10, 20));
   
    velocity = ofVec3f(ofRandom(-8, 1), ofRandom(-8, 1));
 
    
    //❤️////////////////////////
    //🌹创建group测试向量
    groupSepWeight = 0.8f;
    groupDetect = 150;
    //❤️////////////////////////
   
}


//可能是起始数值
Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
    separationWeight = 0.3f;
    cohesionWeight = 0.15f;
    alignmentWeight = 0.1f;
    
    separationThreshold = 50;
    neighbourhoodSize = 300;
    
    position = pos;
    velocity = vel;
}

Boid::~Boid()
{
	
}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

//❤️////////////////////////////////
//🌹设置速率的变化
ofVec3f Boid::setVelocity(float x,float  y)
{
    velocity=ofVec3f(ofRandom(-x, y), ofRandom(-x, y));
}

//🌹创建group之间相互避免碰撞的组 , 增大中间绿色和周围蓝色之间的范围
ofVec3f Boid::groupSep(std::vector<Boid *> &otherBoids)
{
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if(position.distance(otherBoids[i]->getPosition())<groupDetect)
        {
            ofVec3f v = position -  otherBoids[i]->getPosition();
            v.normalize();
            return v;
        }
    }
}




ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	
	for (int i = 0; i < otherBoids.size(); i++)
	{	
		if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position -  otherBoids[i]->getPosition();  //要走的方向
			v.normalize();
			return v;
		}
	}
}




ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition(); //算位置
			count += 1;
		}
	}
	average /= count; //所有位置的平均值
	ofVec3f v =  average - position;  //要走的方向
	v.normalize();
	return v;
}




ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();  //算速度
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - velocity;
	v.normalize();
	return v;
}

//❤️////////////////////////////////
void Boid::update(std::vector<Boid *> &otherBoids,std::vector<Boid *> &otherBirds, ofVec3f &min, ofVec3f &max)
{
    //weight表示力的大小
	velocity += separationWeight*separation(otherBoids);
	velocity += cohesionWeight*cohesion(otherBoids);
	velocity += alignmentWeight*alignment(otherBoids);
    
    //🌹添加速率
    velocity += groupSepWeight*groupSep(otherBirds);
	
	walls(min, max);
	position += velocity; //将速率加到本身的位置
}
//❤️////////////////////////////////


void Boid::walls(ofVec3f &min, ofVec3f &max)
{
    //从左边到右边
	if (position.x < min.x){
		position.x = max.x;
		velocity.x *= 0.1;
	} else if (position.x > max.x){
		position.x = min.x;
		velocity.x *= 0.1;
	}
	
	if (position.y < min.y){
		position.y = max.y;
		velocity.y *= 0.1;
	} else if (position.y > max.y){
		position.y = min.y;
		velocity.y *= 0.1;
	}
	
	
}

void Boid::draw()
{
//    light.setPosition(20,10,300);
//    light.setPosition(ofRandom(20)*ofGetMouseX(),ofRandom(10)*ofGetMouseY(),300);
//    light.enable();
    ofSetColor(ofRandom(0, 255),ofRandom(0, 255),ofRandom(0, 255));
   
    
    //🌹画点
//    ofCircle(position.x, position.y, 5);
    
    //🌹新的速率，
    ofVec3f plusSpeed=velocity;
    if(velocity.x>0||velocity.y>0)
    {
        plusSpeed.x = velocity.x;
    }
    else if(velocity.x<0||velocity.y<0)
    {
        plusSpeed.x = velocity.x*0.1;
        plusSpeed.y = velocity.y*0.1;

    }

//    ofTriangle(position.x,position.y,position.x+cos(60.0)*15-plusSpeed.x*2.2,position.y+sin(60.0)*15-plusSpeed.y*2.2,position.x+sin(60.0)*15-plusSpeed.x*2.2,position.y+cos(60.0)*15-plusSpeed.y*2.2);
    ofCircle(position.x+cos(60.0)*15-plusSpeed.x*0.2, position.y+sin(60.0)*15-plusSpeed.y*0.2, 5);
    
    //🌹原来三角形
    ofTriangle(position.x,position.y,position.x+cos(90.0)*15,position.y+sin(90.0)*15,position.x+sin(90.0)*15,position.y+cos(90.0)*15);
    
    light.disable();
}



