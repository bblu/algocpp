// Source : Candy
// Auther : bblu
//
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Solution{
public:
    int minimalCandy(vector<int> chdRate){
        vector<int> chdIdx = chdRate;

        sort(chdIdx.begin(),chdIdx.end());

        for(int i=0; i<chdIdx.size(); i++){
            
        }
        
        return 0;
    }

};


int main(){
    srand(time(NULL));
    const int chdNum = 10;
    vector<int> chdRate;
    printf("childrenRate[");
    for(int i=0; i<chdNum; i++){
        chdRate[i] = rand() % 100;
        printf("%d,", chdRate[i]);
    }
    printf("\n");

    Solution sol;

    int result = sol.minimalCandy(chdRate);


return 0;
};
