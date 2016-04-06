#include "cluster.h"

namespace Cluster
{


	class Kmeans
	{
	public:
		Kmeans();

		void setK(int c);

		void cluster(KmsNodeVector & in, KmsNodeVector &out);

		void assignCentroid(KmsNode *node, KmsNodeVector &out);

		bool calculateNewCentroid(KmsNodeVector &out, KmsNodeVector &in);
	private:
		int k;

	};

}