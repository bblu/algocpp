// source : https://leetcode.com/problems/happy-number/
// author : bblu
// date : 2016-9-
/*
202. Happy Number  QuestionEditorial Solution  My Submissions
Total Accepted: 88027
Total Submissions: 230689
Difficulty: Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the 
sum of the squares of its digits, and repeat the process until 
the number equals 1 (where it will stay), or it loops endlessly 
in a cycle which does not include 1. Those numbers for which 
this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
		if(n<1)return false;
		if(n==1)return true;
		map<int, bool> mk;
		mk[n]=true;
		while(n != 1){
			n = square(n);
			if(mk.find(n)!=mk.end()){
				//come up again means can never happy
				printf("n=%d is false\n", n);
				return false;	
			}
			mk[n]=true;
			printf("n=%d is true\n", n);
		}
		return true;
    }
	int square(int n){
		int result=0,tmp=0;
		for(; n>0; n/=10){
			tmp = n%10;
			result += tmp * tmp;
		}
		return result;
	}
};


int main(){

	Solution sol;
	sol.isHappy(19);
	sol.isHappy(20);
	return 0;
}

