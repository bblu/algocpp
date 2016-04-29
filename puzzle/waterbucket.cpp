#include <iostream>
#include <deque>
#include <algorithm>
#include <functional>
#include <cstring>
#include <assert.h>

#include "waterbucket.h"

int bucket_capicity[BUCKETS_COUNT]    = {8, 5, 3};
int bucket_begin_state[BUCKETS_COUNT] = {8, 0, 0};
int bucket_final_state[BUCKETS_COUNT] = {4, 4, 0};

void SearchState(std::deque<BucketState> &states);

BucketState::BucketState()
{
     SetBuckets(bucket_init_state);
     SetAction(8, -1, 0);
 }
 
BucketState::BucketState(const int *buckets)
{
    SetBuckets(buckets);
    SetAction(8, -1, 0);
}

BucketState::BucketState(const BucketState& state)
{
    SetBuckets((const int *)state.bucket_s);
    SetAction(state.curAction.water, state.curAction.from, state.curAction.to);
}

bool BucketState::isSameState(const BucketState &that) const
{
    for(int i = 0; i < BUCKETS_COUNT; ++i){
        if(bucket_s[i] != state.bucket_s[i])
            return false;
    }
    return true;
}

void BucketState::setBuckets(int *buckets){
        memcpy(bucket_s,buckets,sizeof(int)*BUCKETS_COUNT);
}
bool BucketState::isBucketEmpty(int bucket)
{
    assert((bucket >= 0) && (bucket < BUCKETS_COUNT)); 
    return (bucket_s[bucket] >= bucket_capicity[bucket]);
}
bool BucketState::canTakeDumpAction(int from, int to)
{
	assert((from >= 0) && (from < BUCKETS_COUNT));
	assert((to >= 0) && (to < BUCKETS_COUNT));
		
	if( (from != to) && !IsBucketEmpty(from) && !IsBucketEmpty(to))
		return true;
	return false;
}

void BucketState::setAction(int water, int from, int to)
{
     curAction.water = water;
     curAction.from  = from;
     curAction.to    = to;	
}
bool BucketState::dumpWater(int from, int to, BucketState &next)
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

bool BucketState::isFinalState()
{
    return isSameState(BucketState(bucket_final_state));
}
void BucketState::printState()
{
	std::cout << "Dump " << curAction.water << "water from " <<
		curAction.from+1 << "to " << curAction.to+1 << ", " << 
		"Buckets water state is: ";
	for(int i=0; i< BUCKET_COUNT; ++i)
		std::cout << bucket_s[i] << " ";
	std::cout << std::endl;
}
//------------------------main----------------------------------
bool IsSameBucketState(BucketState state1, BucketState state2)
{
    return state1.IsSameState(state2);
}

bool IsProcessedState(std::deque<BucketState> &states, 
    const BucketState &newState)
{
     std::deque<BucketState>::iterator it = states.end();
     it = std::find_if(states.begin(), states.end(), 
     std::bind2nd(std::ptr_fun(IsSameBucketState), newState) );

     return (it != states.end());
}

void SearchStateOnAction(std::deque<BucketState> &states, 
    BucketState &current, int from, int to)
{
	if(current.canTakeDumpAction(from, to)){
		BucketState next;
		bool bDump = current.dumpWater(from, to, next);

		if(bDump && !IsProcessedState(states, next)){
			states.push_back(next);
			SearchState(states);
			states.pop_back();
		}
	}
}

void SearchState(std::deque<BucketState> &states)
{
	BucketState current = states.back();
	
	if(current.isFinalState()){
		PrintResult(states);
		return;
	}

	for(int j=0; j<BUCKETS_COUNT; ++j){
		for(int i=0; i<BUCKETS_COUNT; ++i){
			SearchStateOnAction(states, current, i, j);
		}
	}

}
