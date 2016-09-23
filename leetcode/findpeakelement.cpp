// source : find peak element
// author : bblu
/********************************************************************************** 
* A peak element is an element that is greater than its neighbors.
* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
* You may imagine that num[-1] = num[n] = -∞.
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* click to show spoilers.
* Note:
* Your solution should be in logarithmic complexity.
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
#define NINT_MAX  (-INT_MAX-1)
class Solution{
    public:
        int findPeakElement(const vector<int> &nums){
            int n=nums.size();
            int low=0;
            int high= n-1;
            int mid = 0;

            while(low < high){
                mid = low + (high - low)/2;
                if((mid==0 || nums[mid] > nums[mid-1]) &&
                        (mid == n-1 || nums[mid] > nums[mid+1])){
                    return mid;
                }
            
                if(mid>0 && nums[mid-1] > nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }
};

int main(){
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(2);
    Solution sol;

    int i = sol.findPeakElement(vi);
    if(i==2)
        cout << "i=2 is ok" << endl;
return -1;
};
