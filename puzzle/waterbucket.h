#include <deque>
#include <algorithm>
#include <functional>
#include <cstring>
#include <assert.h>

#define BUCKETS_COUNT 3

struct Action
{
	int from;
	int to;
	int water;
};

bool IsBucketEmpty(int id)
{

    return false;
}



struct BucketState
{
	int bucket_s[BUCKETS_COUNT];
    int bucket_capicity[BUCKETS_COUNT];
	Action curAction;
    int dump_water;
    
    void setBuckets(int *buckets){
        memcpy(bucket_s,buckets,sizeof(int)*BUCKETS_COUNT);
    }

	bool canTakeDumpAction(int from, int to)
	{
		assert((from >= 0) && (from < BUCKETS_COUNT));
		assert((to >= 0) && (to < BUCKETS_COUNT));
		
		if( (from != to) && !IsBucketEmpty(from) && !IsBucketEmpty(to))
			return true;
		return false;
	}

	bool dumpWater(int from, int to, BucketState &next)
    {
        next.setBuckets(bucket_s);
        int dump_water = bucket_capicity[to] - next.bucket_s[to];

        if(next.bucket_s[from] >= dump_water){
        next.bucket_s[to] += dump_water;
        next.bucket_s[from] -= dump_water;
        }else{
        next.bucket_s[to] += next.bucket_s[from];
        dump_water = next.bucket_s[from];
        next.bucket_s[from] = 0;
        }

        if(dump_water > 0){
            next.setAction(dump_water, form, to);
            return true;
        }
        return false;
    }

	bool isFinalState()
	{
		return false;
	}
};

