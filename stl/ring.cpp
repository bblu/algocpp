//test ring.h
#include "ring.h"

int main(){
	Ring<string> rs;

	rs.push_back("one");
	rs.push_back("two");
	rs.push_back("three");
	rs.push_back("four");
	rs.push_back("five");

	Ring<string>::iterator it = rs.begin();
	++it; ++it;
	it.insert("six");
	it = rs.begin();
	//twice around the ring
	for(int i=0; i< rs.size()*2; i++)
		cout << *it++ << endl;
}
