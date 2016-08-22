/*72. Edit Distance 
Difficulty: Hard
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
       	int len1 = word1.size();
		int len2 = word2.size();
		if(len1==0)return len2;
		if(len2==0)return len1;
		cout << "len1="<<len1<<" len2= " << len2 << endl;		
		vector<vector<int> > dp(len1+1,vector<int>(len2+1));

		for(int i=0; i< dp.size(); i++)
			dp[i][0]=i;
		for(int j=0; j< dp[0].size(); j++)
			dp[0][j]=j;

		for(int i=1; i< dp.size(); i++){
			for(int j=1; j<dp[i].size();j++){
				if(word1[i-1]==word2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
			}
		}
		return dp[len1][len2];
    }
	int min(int a, int b, int c){
		return std::min(a,std::min(b,c));
	}
};


int main(int argc,char** argv){
	
	string w1="hello";
	string w2="world";
	if(argc>2){
		cout << argc << argv[1] << argv[2]<<endl;
		w1 = argv[1];
		w2 = argv[2];
	}

	Solution sol;
	int dis = sol.minDistance(w1,w2);

	cout << w1 << "," << w2 <<":" << dis << endl;
	return 0;
}
