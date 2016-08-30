/*********************************************************
371. Sum of Two Integers  
Total Accepted: 29411
Total Submissions: 56796
Difficulty: Easy
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
 */
class Solution {
public:
    int getSum(int a, int b) {
        
        int c;
        while(b){
            c = a ^ b;
            b = (a&b)<<1;
            a = c;
        }
        return a; 
    }
};
