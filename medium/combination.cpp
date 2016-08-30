/*
77. Combinations  QuestionEditorial Solution  My Submissions
Total Accepted: 86299 Total Submissions: 238808 Difficulty: Medium
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
//Cnk
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
enum {	debug = 1 };

void print(vector<int> v){
		printf("[");
		for(int j=0; j<v.size(); j++){
			printf("%d,",v[j]);
		}
		printf("]\n");
}
//typedef vector<vector<int> > 
void print(vector<vector<int> > sets){
	printf("[");
	for(int i=0; i<sets.size();i++){
		vector<int> v = sets[i];
			
		printf("[");
		for(int j=0; j<v.size(); j++){
			printf("%d,",v[j]);
		}
		printf("]");
	}
	printf("]\n");
};

class Solution {
	int m_k;
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> cur;
		m_k = k;
        cnk(n,k,cur,result);
        sort(result.begin(),result.end());
		print(result);
        return result;
    }
private:
    void cnk(int n, int k, vector<int> cur, vector<vector<int> > &result)
    {
        if(k==0){
            sort(cur.begin(),cur.end());
            result.push_back(cur);
			static int c=1;
			printf("[%d]-----------------------\t",c++);
			print(cur);
            return;
        }
		if(debug) {
			for(int i=0;i<=m_k-k;i++)
					printf("-");
			printf("[from %d take  %d]\n",n,k);
		}
		if(n < k)return;
        for(int i = n; i > 0 ; i--){
            cur.push_back(i);
			printf("cur.push_back(%d)\t",i);
			print(cur);
            cnk(i-1,k-1,cur,result);
            int k = cur[cur.size()-1];
			cur.pop_back();
			printf("cur.pop_back()=%d\t",k);
			print(cur);
        }
    }
    
};
void unitTest(){

}
int main(int argc,char ** argv){

	if(argc < 3){
		printf("short of input args, need two number like 4 2\n will run unit test...\n");
		unitTest();
		return 0;
	}
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	Solution so;
	so.combine(n, k);



}
