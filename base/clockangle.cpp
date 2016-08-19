//calculat the angle of time by bblu @ 8-19
//
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

static const float deltH  = 30;		//360.0/12.0;
static const float deltM  = 6;		//360.0/60.0;

inline float regular(float angle){
	return angle>180?360-angle:angle;	
}

float calcAngle1(int h, int m){
	float angleM = deltM * m;
	float angleH = deltH * (h + m/60.0f);
	float angle = (angleM - angleH);
	//angle = abs(angle);
	if(angle<0)angle = -angle;
	//std::cout <<"m-h="<<angleM-angleH<< " angle=" << angle <<std::endl;
	return regular(angle);
}

static const float wH = 30;		//360/12
static const float wM = 360;	//360/1

float calcAngle2(float t){
	float delta = ((wM-wH)*t);
	while(delta >= 360)
			delta -= 360;
	return regular(delta);
}
void printAngle(int h, int m=0)
{
	printf("the calcAngle1 of %d:%d is %f\n",h,m,calcAngle1(h,m));
	printf("the calcAngle2 of %d:%d is %f\n",h,m,calcAngle2(h+m/60.0f));
}
void unitTest()
{
	float a=1.2345;
	std::cout << "i donot know why? abs(1.2345) = "<<abs(a)<<std::endl;
	for(int i=1; i<=12; i++){
		printAngle(i);
		printAngle(i,15);
		printAngle(i,30);
		printAngle(i,45);
		printf("-----------------------------\n");
	}

}

int main(int argc,char** argv){
	
	if(argc < 3){
	
		unitTest();
		std::cout<< "* * * unitTest end! * * *"<<std::endl;
	}
	int h = atoi(argv[1]);
	int m = atoi(argv[2]);
	std::cout << "the angle is " << calcAngle1(h,m) << std::endl;


}
