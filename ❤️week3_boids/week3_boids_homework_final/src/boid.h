

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"


class Boid
{

private:	
	ofVec3f position;
	ofVec3f velocity;
    ofVec3f Color;
    
    //❤️////////////////////////
    float groupSepWeight;
    float groupDetect;
    
    
    //❤️////////////////////////
    
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
    
	
	float separationThreshold;
	float neighbourhoodSize;
    
	
	ofVec3f separation(std::vector<Boid *> &otherBoids);
	ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);


public:	
	Boid();
	Boid(ofVec3f &pos, ofVec3f &vel);
    
    //❤️//////////////////////////////////////
    //🌹创建groupsep
    ofVec3f groupSep(std::vector<Boid *> &otherBoids);
    
    
    
    //🌹创建getbird
    ofVec3f getBird();
    ofVec3f setVelocity(float x,float  y);
    
    void update(std::vector<Boid *> &otherBoids,std::vector<Boid *> &otherBirds, ofVec3f &min, ofVec3f &max);
    
    //🌹创建draw 虚拟函数， 是因为我们使用了bird的新文档，而不是直接在boid上面添加
    virtual void draw();
    //❤️////////////////////////////////////////
    //创建light
    ofLight light;
    
    
    
	~Boid();
	
	ofVec3f getPosition();
	ofVec3f getVelocity();

	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
	
	void walls(ofVec3f &min, ofVec3f &max);
	

};





#endif
