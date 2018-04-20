CCC=g++ -std=c++11

all:getIndicesByTarget

getIndicesByTarget:getIndicesByTarget.o
	$(CCC) -o getIndicesByTarget getIndicesByTarget.o
getIndicesByTarget.o:getIndicesByTarget.cpp
	$(CCC) -c getIndicesByTarget.cpp

clean:
	rm *.o getIndicesByTarget