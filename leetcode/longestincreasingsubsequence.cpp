/*************************************************************
300. Longest Increasing Subsequence  
	Total Accepted: 41381
	Total Submissions: 115313
	Difficulty: Medium
Given an unsorted array of integers, find the length of longest 
increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore 
the length is 4. Note that there may be more than one LIS combination, 
it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void printv(vector<int> &v){
printf("[");
for(int i=0; i<v.size(); i++)
	printf("%d ",v[i]);
printf("]\n");
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> sub;
		vector<int> len;
		int maxLen=1;
        for(int i=0; i<nums.size()-1; i++){
			int cur = nums[i];
			sub.push_back(cur);
			for(int j=i+1; j<nums.size(); j++){
				int nxt = nums[j];
				if(sub.back()<nxt){
					sub.push_back(nxt);
				}
			}
			printv(sub);
			maxLen = max(maxLen,(int)sub.size());
			sub.clear();
		}
		return maxLen;
    }
};

int main(){
	
	vector<int> nums;
	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(101);
	nums.push_back(18);
			
	Solution sol;
	int ilen = sol.lengthOfLIS(nums); 
	printf("Longest Incresing Subsequence is %d\n",ilen);
	return 0;
}
