
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = (int)s.size();
        int curLeft=0,maxLen=1;
        int i,j;
        for(i=1;i< size; i++){
            int tmpLeft0=0,tmpLen0=0;
            int tmpLeft1=0,tmpLen1=0;
            
            for(j=1; j<=i; j++){
                int jLeft=i-j;
                int jRight=i+j-1;
                if(tmpLeft0 > -1 && s[jLeft]==s[jRight]){
                    tmpLeft0 = jLeft;
                    tmpLen0 = j+j;
                    //cout << "i=" << i << ", j=" << j << ", tmpLeft=" << tmpLeft0 << ", len=" << tmpLen0 << endl;
                    if(tmpLen0 > maxLen){
                        maxLen = tmpLen0;
                        curLeft = tmpLeft0;
                        cout <<"|-curLeft="<<curLeft<< ", length="<< maxLen << ", i=" << i <<", sub="<< s.substr(curLeft,maxLen)<<endl;
                    }
                }else{
                    tmpLeft0 = -1;
                }
                jRight=i+j;
                if(tmpLeft1 > -1 && s[jLeft]==s[jRight]){
                    tmpLeft1 = jLeft;
                    tmpLen1 = j+j+1;
                    //cout << "i=" << i << ", j=" << j << ", tmpLeft=" << tmpLeft1 << ", len=" << tmpLen1 << endl;
                    if(tmpLen1 > maxLen){
                        maxLen = tmpLen1;
                        curLeft = tmpLeft1;
                        cout <<"|-curLeft="<<curLeft<< ", length="<< maxLen << ", i=" << i <<", sub="<< s.substr(curLeft,maxLen)<<endl;
                    }
                }else{
                    tmpLeft1 = -1;
                }
            }
        }
        return s.substr(curLeft,maxLen);
    };
};

int main(){
    string s ="aaabaaaa";
    Solution *sol = new Solution();
    string pal = sol->longestPalindrome(s);
    cout << "palindrome:" << pal << endl;
    return 0;
}
