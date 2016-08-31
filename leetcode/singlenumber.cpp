/********************************************
136. Single Number  == 389. Find the Difference 
Total Accepted: 148225
Total Submissions: 287841
Difficulty: Easy
Given an array of integers, every element appears twice
 except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

Subscribe to see which companies asked this question
*****************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c=nums.size();
        map<int,int> single;
        
        for(int i=0; i<c; i++){
            single[nums[i]]++;
        }
        map<int,int>::iterator i = single.begin();
        for(; i!=single.end(); ++i){
            if ((*i).second == 1)    
                return (*i).first;
        }
        return -1;
    }
};
