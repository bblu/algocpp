#include "waterbucket.h"

void SearchState(std::deque<BucketState> &states);

bool IsSameBucketState(BucketState &state,BucketState &that)
{
    return false;
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
