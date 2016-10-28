/*
 347. Top K Frequent Elements   QuestionEditorial Solution  My Submissions
Total Accepted: 36347 Total Submissions: 81222 Difficulty: Medium Contributors: Admin
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution{
public:
	vector<int> topKFrequent(vector<int> &nums, int k){
		map<int,int> frequent;
		for(int i=0; i<nums.size(); i++){
			frequent[nums[i]]++;
		}
		vector<int> r;
		map<int,int>::iterator it=frequent.begin();
		for(;it!=frequent.end() && r.size()<k; it++){
			cout << it->first << it->second << endl;
			r.push_back(it->first);
		}	
	}
};

int main(){
	Solution sol;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(3);
	sol.topKFrequent(nums,2);

	return 0;
}

