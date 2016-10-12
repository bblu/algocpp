#include <stdlib.h>

bool isBadVersion(int version);


class Solution{
    public:
        int firstBadVersion(int n){
            int low = 1, high = n;
            while(low >0 && high < n){
                //int mid = (low + high)/2;
                int mid = low + (low + high)/2;
                if(isBadVersion(mid) && !isBadVersion(mid-1)
                    return mid;
                if(isBadVersion(mid)){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            return -1;

        }

};

