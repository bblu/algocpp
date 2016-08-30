/**********************************************************
283. Move Zeroes  
Total Accepted: 110823
Total Submissions: 241188
Difficulty: Easy
Given an array nums, write a function to move all 0's to the 
end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function,
nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
****************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0){
                c++;
                for(int j=i;j<nums.size()-1;j++){
                    nums[j]=nums[j+1];
                 }
                nums[nums.size()-1]=0;
            }
        }
    }
    void myMoveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0){
                c++;
                for(int j=i;j<nums.size()-1;j++){
                    nums[j]=nums[j+1];
                 }
                nums[nums.size()-1]=0;
            }
	if(nums[i]==0)i--;
        }

    }
};

