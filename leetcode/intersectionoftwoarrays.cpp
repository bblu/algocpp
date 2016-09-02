// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : bblu
// Date   : 2016-09-02
/********************************************************************************** 
349. Intersection of Two Arrays  QuestionEditorial Solution  My Submissions
Total Accepted: 42915 Total Submissions: 96312 Difficulty: Easy
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
**********************************************************************************/


//60 test cases passed.Status: Accepted Runtime: 20 ms
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> inter;
        sort(nums1.begin(),nums1.end());
        for(int i=0; i<nums1.size(); i++){
            int cur = nums1[i];
            if(i && cur==nums1[i-1]) continue;
            for(int j=0; j<nums2.size(); j++){
                if( cur == nums2[j]){
                    inter.push_back(cur);
                    break;
                }
            }
        }
        return inter;
    }
};
//Runtime: 12ms
class Solution2 {
public:
    set <int> inter1, inter2;//we use sets so as to avoid duplicates
    vector <int> solution;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
            inter1.insert(nums1[i]);//get all of the unique elements in nums1 sorted
        for(int i = 0; i < nums2.size(); i++)
            if(inter1.find(nums2[i]) != inter1.end())//search inter1 in O(logN)
                inter2.insert(nums2[i]);//populate the intersection set
        for(set<int>::iterator it = inter2.begin(); it != inter2.end(); ++it)
            solution.push_back(*it);//copy the set into a vector
        return solution;
    }
};
