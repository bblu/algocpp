// cluster.cpp : Defines the exported functions for the DLL application.
//

#include "cluster.h"
namespace Cluster
{

	void Vec3f::set(float vx, float vy, float vz){
		x = vx;
		y = vy;
		z = vz;
	}

	Vec3f Vec3f::operator - (const Vec3f &that){
		Vec3f obj(x, y, z);
		obj.x -= that.x;
		obj.y -= that.y;
		obj.z -= that.z;
		return obj;
	}

	void Vec3f::operator +=(const Vec3f &that){
		this->x += that.x;
		this->y += that.y;
		this->z += that.z;
	}

	void Vec3f::operator /=(const float & d){
		this->x /= d;
		this->y /= d;
		this->z /= d;
	}

	Vec3f KmsNode::getMean()const
	{
		Vec3f v(0);
		for (KmsNode *n : children){
				v += n->location;			
		}
		if (children.size() > 1)
			v /= children.size();
		return v;
	}


	void KmsNodeVector::getRadomK(int k, KmsNodeVector &out) const
	{
		std::map<int, int> selectMap;
		int size = this->size();
		printf("radomK = ");
		for (int i = 0; i < k;)
		{
			int p = getRand(0, size);
			while (selectMap[p] < 1)
			{
				out.push_back(this->at(p));
				selectMap[p] = 1;
				printf("%i,", p);
				i++;
			}
		}
		printf("\n");
	}

	KmsNode* KmsNodeVector::getNearest(const Vec3f &p)const
	{
		float small = FLT_MAX;
		KmsNode *selNode = nullptr;
		for (KmsNode *n : *this)
		{
			float dis = (n->location - p).length();
			if (dis < small){
				small = dis;
				selNode = n;
			}
		}
		return selNode;
	}
}