// getIndicesByTarget.cpp @ 2018-04-14
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
    //bblu @ 2018-04-20
    void getIndicesByTarget2(int* num,int len,int tar,int (&indices)[2]){
        if ( len < 2) return;
        if (len ==2 && num[0]+num[1]==tar){
            indices[0] = 0;
            indices[1] = 1;
            return;
        }
        for(int i = 0; i < len-1; i++){
            int tmp = -1;
            for(int j = i; j < len; j++){
                if (tmp < 0 && num[j] < tar){
                    indices[0] = i + j;
                    tmp = tar - num[j];
                }else if(tmp == num[j]){
                    indices[1] = i + j;
                    return;
                }
            }
        }
    }
};

int main(){
    int num[6] = {1,2,10,7,5,8};
    int len = sizeof(num)/sizeof(num[0]);
    int tar = 7;
    int indices[2] = {-1,-1};
    Solution sol;
    sol.getIndicesByTarget(num, len, tar, indices);
    if (indices[1] > 0){
        printf("get indices[%d,%d] of number array.\n",indices[0],indices[1]);
    }else{
        printf("sorry world!");
    }
    sol.getIndicesByTarget2(num, len, tar, indices);
    if (indices[1] > 0){
        printf("get indices[%d,%d] of number array.\n",indices[0],indices[1]);
    }else{
        printf("sorry world!");
    }
    return 0;
}
