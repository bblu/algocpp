/*
27. Remove Element  QuestionEditorial Solution  My Submissions
Total Accepted: 144298
Total Submissions: 403886
Difficulty: Easy
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
	Given input array nums = [3,2,2,3], val = 3
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                nums[idx++]=nums[i];
            }
        }
        return idx;
    }
};
