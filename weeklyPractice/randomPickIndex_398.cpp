/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.
Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.
Example:
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);
// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);
// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);*/


#include <stdlib.h>
#include <vector>
#include <random>
using namespace std;

class Solution {
private:
    vector<int> nums;
    std::random_device rd;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        auto p = begin(nums);
        auto e = end(nums);
        int i = -1;
        int c = 0;
        std::mt19937 gen(rd());
        while (p != e){
            if (*p == target){
                c++;
                std::uniform_int_distribution<> dis(1, c);
                if (dis(gen) == 0){
                    i = p - begin(nums);
                    break;
                }
            } 
        }
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
int main(){
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution *sol = new Solution(nums);
    sol->pick(1);
    
    return 0;
}