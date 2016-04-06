#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <vector>
#include <map>

namespace Cluster
{
	enum DebugFlag_T{
		DebugFlag =1
	};
	static int getRand(int min, int max)
	{
		return rand() % (max - min) + min;
	}

	class INode
	{
	public:
		INode(int i) :id(i), status(0){}
		int id;
		int status;
	};

	struct Vec3f{
		float x, y, z;

		Vec3f():Vec3f(FLT_MIN){}
		Vec3f(float a) :x(a), y(a), z(a){}
		Vec3f(float vx, float vy, float vz):x(vx), y(vy), z(vz)	{}

		void set(float vx, float vy, float vz);

		Vec3f operator - (const Vec3f &that);

		void operator +=(const Vec3f &that);

		void operator /=(const float & d);

		float length(){	return sqrt(x*x + y*y + z*z);
		}
	};
	class KmsNode;
	class KmsNodeVector :public std::vector< KmsNode* >
	{
	public:
		enum Status{
			NORMAL,
			INPUT_IS_EMPTY,
			K_IS_INLEAGUE
		};
	public:
		void getRadomK(int k, KmsNodeVector &out) const;



		KmsNode* getNearest(const Vec3f &p)const;

		int status{ NORMAL };
	};
		
		
	class KmsNode :public INode
	{
	public:		
		KmsNode * parent;
		KmsNodeVector children;
		Vec3f location;
	public:
		KmsNode(int i):INode(i){}
		Vec3f getMean() const;
		float getCost(const KmsNode &that)
		{
			return (location - that.location).length();
		}
	};

	



}