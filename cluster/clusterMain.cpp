#include "kmeans.h"
using namespace Cluster;
int main(int argc,char**argv)
{
	int k=5;
	int s=10;
	for(int i=1;i<argc;i++){
		char* obj=argv[i];
		printf("%s\n",obj);
		if(i==1)k=atoi(obj);
		if(i==2)s=atoi(obj);
	}
	if(k<1 || s<1){
		printf("error input k=%i,s=%i",k,s);	
		return 1;
	}

	KmsNodeVector in,out;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			int idx = i * 10 + j;
			KmsNode  *node = new KmsNode(idx);
			
			int dy = i * 10 + getRand(-2, 2);
			int dx = j * 10 + getRand(-2, 2);
			printf("(%i,%i)", dx, dy);
			node->location.set(dx, dy, 0);
			in.push_back(node);
		}
		printf("\n");
	}

	Kmeans kms;
	kms.setK(k);

	kms.cluster(in, out);

	return 0;
}
