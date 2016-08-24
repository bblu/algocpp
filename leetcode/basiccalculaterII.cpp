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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		stack<char> ops;
		stack<int> vals;
		for(int i=0; i< s.size(); i++){
			char cur = s[i];
			if(isspace(cur))
				continue;
			if(isdigit(cur)){
				string val;
				val+=cur;
				while(isdigit(s[i+1])){
					val+=s[i+1];
					i++;
				}
				// atoi param need to be a const char*
				vals.push(atoi(val.c_str()));
				continue;
			}
			if(isOperator(cur)){
				while(!ops.empty() && priority(ops.top()) >= priority(cur) ){
					int y = vals.top(); vals.pop();
					int x = vals.top(); vals.pop();
					char op = ops.top(); ops.pop();
					vals.push(calculateExp(x,y,op));
				}
				ops.push(cur);
			}
		
		}
		while(!ops.empty()){
			int y = vals.top(); vals.pop();
			int x = vals.top(); vals.pop();
			char op = ops.top(); ops.pop();
			vals.push(calculateExp(x,y,op));
		}
		return vals.top();
    }

	bool isOperator(char op){
		return (op=='+' || op=='-' || op=='*' || op=='/');
	}
	
	int priority(char op){
		if(op=='*' || op=='/')
			return 2;
		if(op=='+' || op=='-')
			return 1;
		return 0;
	}

	int calculateExp(int x, int y, char op){
		switch(op){
			case '+': return x + y;
			case '-': return x - y;
			case '*': return x * y;
			case '/': return x / y;
		}
		printf("Error op %s for(%d,%d) \n", &op, x, y);
		return -1;
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
