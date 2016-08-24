/***************************************************************
331. Verify Preorder Serialization of a Binary Tree  

	Total Accepted: 19346
	Total Submissions: 58013
	Difficulty: Medium

One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string 
"9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a 
correct preorder traversal serialization of a binary tree. Find an 
algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer 
or a character '#' representing null pointer.

You may assume that the input format is always valid, for example 
it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*******************************************************************/
// bblu @ xiamen 2016-08-24
// delete two join # and make the pre parent node to # and in the end leave only a #
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
//assume the node value is a single digit 
class Solution {
public:
    bool isValidSerialization(string preorder) {
		if(preorder.size()<5)
			return false;

		size_t pos = preorder.find(",#,#");
        while(pos > 0 && preorder.size() > 5 ){
			printf("pos=%ld, preorder = '%s'\n",pos,preorder.c_str());
			preorder.erase(pos,4);
			preorder[pos-1]='#';
			pos = preorder.find(",#,#");
		}
		printf("pos=%ld, preorder = '%s'\n",pos,preorder.c_str());
		if(preorder.size()>1)
				return false;
		return preorder=="#";
    }
};

int main(){
	
	//string po1="9,3,4,#,#,1,#,#,2,#,6,#,#";
	string po1="9,#,1,#,#,#";

	Solution sol;
	bool b = sol.isValidSerialization(po1);
	if(b)
		printf("the string is valid preorder serialization\n");
	else
		printf("the string is invalid preorder serialization\n");
	return 0;
}
