/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        map<int,int> counter;
        for(int i=0;i<nums.size();i++){
            counter[nums[i]]++;
        }
        map<int,int>::iterator i = counter.begin();
        for(;i!=counter.end();i++){
            if(i->second == 1){
                result.push_back(i->first);
            }
        }
        return result;
    }
};
