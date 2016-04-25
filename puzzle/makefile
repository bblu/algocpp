CCC=g++
waterBucket:waterbucket.o
	$(CCC) -o waterBucket waterbucket.o
waterbucket.o:waterbucket.cpp waterbucket.h
	$(CCC) -c waterbucket.cpp

clean:
	rm *.o waterBucket
