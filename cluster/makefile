CCC=g++ -std=c++11
cluster:cluster.o kmeans.o clusterMain.o
	$(CCC) -o cluster cluster.o kmeans.o clusterMain.o
cluster.o:cluster.cpp cluster.h
	$(CCC) -c cluster.cpp
kmeans.o:kmeans.cpp kmeans.h
	$(CCC) -c kmeans.cpp
clusterMain.o:clusterMain.cpp cluster.cpp kmeans.cpp
	$(CCC) -c  cluster.cpp kmeans.cpp clusterMain.cpp

clean:
	rm *.o cluster
