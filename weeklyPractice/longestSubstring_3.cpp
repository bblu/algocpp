//
//  main.cpp
//  weekly
//
//  Created by lu wenbo on 2018/5/11.
//  Copyright © 2018 lu wenbo. All rights reserved.
/*
3. Longest Substring Without Repeating Characters
DescriptionHintsSubmissionsDiscussSolution
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
    a b c a d d
 
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
    //abcacb
    int lengthOfLongestSubstring(std::string s){
        //记录每个字符之前最大的起始位置
        std::vector<int> preCharPos(255,-1);
        int strLen = (int)s.length();
        if (strLen < 2) return strLen;
        int maxLen = 1;
        int curPos = -1;
        int prePos = 0;
        for(int i = 0; i<strLen; i++){
            prePos = preCharPos[s[i]];
            curPos = std::max(curPos,prePos);
            int curLen = i - curPos;
            preCharPos[s[i]] = i;
            maxLen = std::max(maxLen, curLen);
        }
        return maxLen;
    };
    int lengthOfLongestSubstring1(std::string s) {
        this->s = s;
        int strlen =(int)s.length();
        if (strlen < 2) return strlen;
        if (strlen ==2) return s[0]==s[1] ? 1 : 2;
        int start = 0;
        int sublen = 1;
        int longest = 1;
        for(int pos=1; pos < strlen; pos++){
            if(hasCurrentChar(start,pos)){
                printf( "has s:%i, p:%i, l:%i\n",start, pos, sublen);
                start++;
                pos = start;
                if(sublen > longest) longest = sublen;
                //tempArray.push_back(sublen);
                sublen = 1;
            }else{
                sublen++;
                printf( "else sublen++=%i\n",sublen);
            }
        }
        if(sublen > longest) longest = sublen;
        return longest;
        //sort(tempArray.begin(), tempArray.end());
        //return tempArray.back();
    }
    private:
    std::string s;
    //std::vector<int> tempArray;
    bool hasCurrentChar(int start, int pos){
        char p = s[pos];
        for(int i=start; i < pos; i++){
            if(p == s[i]) {
                printf( "cmp start:%i, pos[%i]=%c\n",start, pos, p);
                return true;
            }
        }
        return false;
    }
    
};

int main(){
    Solution *sol = new Solution();
    string str = "cdd";
    int longest = sol->lengthOfLongestSubstring(str);
    printf("longestsubstring len=%i\n", longest);
}
