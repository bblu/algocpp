/***********************************************************
129. Sum Root to Leaf Numbers 
	Total Accepted: 85625
	Total Submissions: 252918
	Difficulty: Medium
Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which 
represents the number 123.
Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>

using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
	vector<int> vsum;
public:
	Solution(){
		srand(time(NULL));
	}
    int sumNumbers(TreeNode* root) {
    	if(root==NULL)
			return 0;
		int sum = 0;
		if(random()%2)
			sumNode1(root,sum);
		else
			sumNode2(root,sum);
		return sum;
    }
	
	void sumNode1(TreeNode* node,int &sum){
		if(node->left==NULL && node->right==NULL){
			sum += node->val;
			printf("\tsum + %d = %d\n",node->val,sum);
			return;
		}

		if(node->left){
			node->left->val += node->val * 10;
			sumNode1(node->left,sum);
		}

		if(node->right){
			node->right->val += node->val * 10;
			sumNode1(node->right,sum);
		}	
	}
	void sumNode2(TreeNode* root,int &sum){
		if(root==NULL)
			return;
		vector<TreeNode*> buf;
		buf.push_back(root);

		while(buf.size()){
			TreeNode *node = buf.back();
			buf.pop_back();
			if(node->left==NULL && node->right==NULL){
				sum += node->val;
				printf("\tsum + %d = %d\n",node->val,sum);
				//return;
			}

			if(node->left){
				node->left->val += node->val * 10;
				printf("push node->left val=%d\n",node->left->val);
				buf.push_back(node->left);
			}

			if(node->right){
				node->right->val += node->val * 10;
				printf("push node->right val=%d\n",node->right->val);
				buf.push_back(node->right);
			}	
		}
	}
};
/*the test tree
 *		1
 *	   / \
 *	  2  3
 *	 /\	 /\
 *  4 5  6 7
 * /        \
 *8			 9
 *
 */
void initTree(TreeNode *tree){
	TreeNode *t4= new TreeNode(4);
	t4->left 	= new TreeNode(8);
	TreeNode *t2= new TreeNode(2);
	t2->left 	= t4;
	t2->right 	= new TreeNode(5);
	TreeNode *t3= new TreeNode(3);
	t3->left 	= new TreeNode(6);
	t3->right 	= new TreeNode(7);
	t3->right->right = new TreeNode(9);
	tree->left 	= t2;
	tree->right = t3;
}
int main(){
	TreeNode *tree=new TreeNode(1);
	initTree(tree);
	Solution sol;
	int sum = sol.sumNumbers(tree);
	printf("sum=%d\n",sum);
	return 0;
}

