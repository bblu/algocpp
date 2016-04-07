
#include "kmeans.h"

using namespace Cluster;


Kmeans::Kmeans()
{

}
void Kmeans::setK(int c)
{
	k = c;
}

void Kmeans::cluster(KmsNodeVector & in, KmsNodeVector &out)
{
	if (in.empty()){
		out.status = KmsNodeVector::INPUT_IS_EMPTY;
		return;
	}
	else if (in.size() <= k){
		out.status = KmsNodeVector::K_IS_INLEAGUE;
		return;
	}
	in.getRadomK(k,out);

	for (KmsNode *n : in){
		assignCentroid(n, out);
	}
	int c = 0;
	for (KmsNode *n : out){
		printf("cen[%i]child=%lu\n", n->id, n->children.size());
		c += n->children.size();
	}
	printf("rr--ac=%i\n", c);
	while(calculateNewCentroid(out, in)){
		for (KmsNode *n : in){
			assignCentroid(n, out);
		}
		c = 0;
		for (KmsNode *n : out){
			printf("cen[%i]child=%lu\n", n->id,n->children.size());
			c += n->children.size();
		}
		printf("rr--ac=%i\n", c);

	}

}

void Kmeans::assignCentroid(KmsNode *node, KmsNodeVector &out)
{
	float small = FLT_MAX;
	KmsNode *selNode = nullptr;
	for (KmsNode *cen : out)
	{
		float cost = node->getCost(*cen);
		if (cost < small){
			small = cost;
			selNode = cen;
			//printf("sel=%i;", selNode->id);
		}
	}
	node->parent = selNode;
	selNode->children.push_back(node);
}

bool Kmeans::calculateNewCentroid(KmsNodeVector &out, KmsNodeVector &in)
{
	bool chg = false;
	for (KmsNode *cen : out)
	{
		Vec3f meaPos = cen->getMean();
		cen->children.clear();
		float dis = (cen->location - meaPos).length();
		KmsNode *tmp = in.getNearest(meaPos);
		int cid = cen->id;
		if (tmp->id != cen->id){
			cen->id = tmp->id;
			cen->location = tmp->location;		
			chg = true;
		}
		//printf("mean(%i,%i)", (int)meaPos.x, (int)meaPos.y);
		printf("[%i]--%f-->[%i]\n", cid, dis, cen->id);
	}
	return chg;
}
