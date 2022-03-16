//
//  main.cpp
//  First_project
//
//  Created by mel on 2022/1/15.
//

#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "some_objects.hpp"


using namespace std;

//int myInt = 2.0;
//float myP = 3.14159;
//string myString = "Hey there";

myClass bubbins1;
myClass bubbins2;


int main(int argc, const char * argv[]) {

  //  -------------
    cout << "Ten numbers queued in sequence:" << endl;
    int i;
    for(i=1;i<=10;i++)
    {
    cout<<" "<<i;
    cout<<endl;
    }
    
    //  -----------------------------------//
    cout << "Using class:" << endl;
        float anotherFloat = bubbins1.myFunc(3,10,20)*bubbins2.myFunc(3,10,50);
        cout<< anotherFloat<<endl;
    
    return 0;
    
        
}
