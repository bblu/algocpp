#include "kmeans.h"
using namespace Cluster;
int main()
{

	KmsNodeVector in,out;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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

	Kmeans k;
	k.setK(5);

	k.cluster(in, out);

	return 0;
}
