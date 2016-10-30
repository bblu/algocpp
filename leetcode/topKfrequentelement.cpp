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
class Solution2 {
    struct element{
        int number,frequency;
        bool operator < (const element arg) const{
            return frequency < arg.frequency;
        }
    };
    priority_queue <element> sol;//a heap auto sorted the order by frequency
    vector<int> solution; 
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1;
        for(; i < nums.size(); i++){
            int freq = 1;
            while(i<nums.size() && nums[i]==nums[i-1]){
                i++;
                freq++;
            }
            element e;
            e.number = nums[i-1];
            e.frequency = freq;
            sol.push(e);
        }
		// in case of the only one element
        if(i==nums.size()){
            element e;
            e.number = nums[i-1];
            e.frequency = 1;
            sol.push(e);
        }
        while(k){
            solution.push_back(sol.top().number);
            sol.pop();
            k--;
        }
        return solution;
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

