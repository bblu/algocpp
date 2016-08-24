/**************************************************************
384. Shuffle an Array
	Total Accepted: 4503
	Total Submissions: 9928
	Difficulty: Medium
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. 
Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
***************************************************************/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
void printv(vector<int> &v){
	if(v.empty()){
		printf("Empty vector...\n");
		return;
	}
	printf("[");
	for(int i=0; i<v.size(); i++)
		printf("%d ",v[i]);
	printf("]\n");
}
class Solution {
public:
    Solution(vector<int> nums):_nums(nums) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		vector<int> shu = _nums;
		int len = _nums.size();
        for(int i=0; i<len; i++){
			int tmp = shu[i];
			int idx = random()%len;
			shu[i]=shu[idx];
			shu[idx]=tmp;
		}
		return shu;
	}
private:
	vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
 	Solution obj(nums);
	printv(nums);
  	for(int i=0; i<4; i++){
		vector<int> param_2 = obj.shuffle();
		printv(param_2);
	}
  	vector<int> param_1 = obj.reset();
	printv(param_1);

	return 0;
}
