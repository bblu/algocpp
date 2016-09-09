/*
169. Majority Element  QuestionEditorial Solution  My Submissions
Total Accepted: 138984
Total Submissions: 321725
Difficulty: Easy
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/
// 43 test cases passed.Status: Accepted Runtime: 28 ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s = nums.size();
        if(s<3)
            return nums[0];
            
        map<int,int> counter;            
        for(int i=0; i<s; i++){
            if(++counter[nums[i]] > s/2)
                return nums[i];
        }
        return -1;
    }
};
