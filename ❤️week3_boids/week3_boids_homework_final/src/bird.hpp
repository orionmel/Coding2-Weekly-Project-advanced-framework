
#ifndef bird_hpp
#define bird_hpp

#include <stdio.h>
#include <boid.h>



class Bird : public Boid
{

    
public:
    //这是我们派生的Babies类的新构造函数
    //这里在新类的头文件中我们宣布我们是
    //改变继承的draw()函数的作用
    void draw();
    
};
#endif /* bird_hpp */
