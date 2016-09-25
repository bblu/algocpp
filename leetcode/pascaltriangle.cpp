/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Subscribe to see which companies asked this question
*/
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<vector<int> > generate(int numRows) {
    vector<vector<int> > tri;
    for(int i=0;i<numRows;i++){    
        vector<int> vj;
        if(i==0){
            vj.push_back(1);
        }else{    
            vj.push_back(1);
            //int last=tri[i-1][0];
            for(int j=0; j<tri[i-1].size()-1; j++){
                vj.push_back(tri[i-1][j]+tri[i-1][j+1]);
                //int next = tri[i-1][j+1] ;
                //vj.push_back(last+next);
                //cout << "l=" << last << ", n="<<next<<", v="<<last+next << endl;
                //last = next;
            }
            vj.push_back(1);
        }
        tri.push_back(vj);
    }
    print(tri,numRows);
    return tri;
}
private:
    inline int getVal(const vector<vector<int> > &tri, int i, int j,int c){
        if(j==0 || j==c) return 0;
        return tri[i-1][j];
    }
    
    void print(vector<vector<int> > &vv,int c){
        for(int i=0;i<vv.size();i++){
            for(int s=0; s<c-i; s++)
                cout << "*";
            cout <<"[";
            for(int j=0; j<vv[i].size(); j++){
                cout << vv[i][j]<<",";
            }
            cout << "]" << endl;
        }
    }
};

int main(){
    Solution sol;

    sol.generate(5);
    return 0;
}
