//:c07 stlshape2.cpp
//stlshape with the purge() function
//
#include <iostream>
#include <vector>
#include "purge.h"
using namespace std;

class Shape{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Circle: public Shape{
	void draw(){ cout << "Circle::draw"<< endl;  }
	~Circle(){ cout << "~Circle" << endl; }
};

class Triangle: public Shape{
	void draw(){ cout << "Triangle::draw"<< endl; }
	~Triangle(){cout << "~Triangle"<< endl; }
};

class Square: public Shape{
	void draw(){ cout << "Square::draw"<< endl; }
	~Square(){cout << "~Square"<< endl; }
};

int main(){
	typedef std::vector<Shape*> Container;
	typedef Container::iterator Iter;
	Container shapes;
	shapes.push_back(new Circle);
	shapes.push_back(new Square);
	shapes.push_back(new Triangle);
	for(Iter i = shapes.begin(); i!=shapes.end(); ++i)
		(*i)->draw();
	purge(shapes);
	
}
