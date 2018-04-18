// getIndicesByTarget.cpp @ 2018-04-04
// 
#include <stdlib.h>
#include <stdio.h>
class Solution{
    //
public:
    void getIndicesByTarget(int* num,int len,int tar,int (&indices)[2]){
        int tmp = -1;
        for(int i = 0; i < len; i++){
            if (tmp < 0 && num[i] < tar){
                indices[0] = i;
                tmp = tar - num[i];
            }else if(tmp == num[i]){
                indices[1] = i;
                return;
            }
        }
    }
};

int main(){
    int num[5] = {2,10,7,5,8};
    int len = sizeof(num)/sizeof(num[0]);
    int tar = 7;
    int indices[2] = {-1,-1};

    Solution *sol = new Solution();
    sol->getIndicesByTarget(num, len, tar, indices);
    if (indices[1] > 0){
        printf("get indices of number array.");
    }else{
            printf("sorry world!");
    }
    return 0;
}
