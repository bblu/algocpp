/****************************************************
﻿227. Basic Calculator II 
	Total Accepted: 28657
	Total Submissions: 107769
	Difficulty: Medium
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
****************************************************/
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

class Solution {
	struct Op{
		string val;
		Op *left;
		Op *right;
		Op(string str):val(str),left(NULL),right(NULL){}
	}
public:
    int calculate(string s) {
    	Op *root=NULL;
		string val;
		for(int i=0; i< s.size(); i++){
			char cur = s[i];
			if(isOp(cur)){
				Op * op = new Op(val);
				if(root==NULL){
					root = new Op(cur);
					root->left = op;
				}
				else
				{

				}
				val.clear();
			}else{
				val+=cur;
			}
		
		}
    }

	bool isOp(char op){
		return (op=='+' || op=='-' || op=='*' || op=='/');
	}


};

int main(int argc,char** argv){
	string exp ="3+2*2 ";
	if(argc>1)
		exp = argv[1];

	Solution sol;
	int result = sol.calculate(exp);

	printf("%s = %d\n",exp.c_str(),result);

}
