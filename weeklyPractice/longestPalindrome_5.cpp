
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxl = 1,curi=0,curj=0;
        int size = s.size();
        int half = size/2.0+1;
        for(int i=0;i<half;i++){
            for(int j=i+1;j<half;j++){
                string sub1 = s.substr(i,j);
                string sub2 = s.substr(i+j-1,j);
                cout << "sub1=" << sub1 << ", sub2=" << sub2 << endl;
                for(int k=0;k<j;k++){
                    cout << "(" << i << "," << j << "," << k <<") : [j-k]="<< j-k<<" " <<s[j-k]<<", [j+k]="<< j+k<<" " <<s[j+k]<<endl;
                    if(s[j-k]!=s[j+k]){
                        cout << "break" <<endl;
                        break;
                    }
                }
                if (j+j>maxl) {
                    maxl = j+j;
                    curi=i;curj=j;
                    cout << "new cur=" << s.substr(i,j+j)<< ", maxl=" << maxl << endl;
                }
            }
        }
        return s.substr(curi,maxl);
    }
};

int main(){
    string s ="alsabcdcbaxy";
    Solution *sol = new Solution();
    string pal = sol->longestPalindrome(s);
    cout << "palindrome:" << pal;
    return 0;
}
