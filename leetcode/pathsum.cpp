/*************************************************************
112. Path Sum  	Total Accepted: 117416
		Total Submissions: 366693
		Difficulty: Easy
Given a binary tree and a sum, determine if the tree has a 
root-to-leaf path such that adding up all the values along 
the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 
which sum is 22.
************************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	Solution(){
		srand(time(NULL));
	}
    bool hasPathSum(TreeNode* root, int sum) {
        int val = root->val;
		if(!root)
			return false;
		else if(sum < val)
			return false;
		if(random()%2){
			printf("transPathSum1\n");
			return transPathSum1(root,val,sum);
		}
		else
		{
			printf("transPathSum2\n");
			return transPathSum2(root,sum);
		}
    }

	bool transPathSum1(TreeNode* node, int val,int sum){
		if(node && !node->left && !node->right){
			printf("val=%d, sum=%d\n",val,sum);
			if(val==sum)
				return true;
		}
		if(node->left){
			printf("left val+%d=%d\n",node->left->val,val+node->left->val);
		return false;
			if(transPathSum1(node->left,val+node->left->val,sum))
				return true;
		}

		if(node->right){
			printf("right val+%d=%d\n",node->right->val,val+node->right->val);
			if(transPathSum1(node->right,val+node->right->val,sum))
				return true;
		}
	}
	bool transPathSum2(TreeNode* root,int sum){
		vector<TreeNode*> buf;
		buf.push_back(root);
		while(buf.size()){
			TreeNode* node = buf.back();
			buf.pop_back();
			if(node->left==NULL && node->right==NULL){
				if(node->val == sum)
					return true;
			}

			if(node->left){
				node->left->val+=node->val;
				printf("left val+%d=%d\n",node->val,node->left->val);
				buf.push_back(node->left);
			}

			if(node->right){
				node->right->val+=node->val;
				printf("right val+%d=%d\n",node->val,node->right->val);
				buf.push_back(node->right);
			}
		}
	}
};
void initTree(TreeNode *tree){
	TreeNode *t11=new TreeNode(11);
	t11->left 	= new TreeNode(7);
	t11->right 	= new TreeNode(2);
	TreeNode *t4= new TreeNode(4);
	t4->right 	= new TreeNode(1);
	TreeNode*t42= new TreeNode(4);
	t42->left 	= t11;
	TreeNode *t8= new TreeNode(8);
	t8->left 	=new TreeNode(13);
	t8->right 	= t4;
	tree->left 	= t42;
	tree->right = t8;
}
int main(){
	TreeNode *tree=new TreeNode(5);
	printf("5\n");

	initTree(tree);
	printf("init\n");
	Solution sol;
	int sum[]={100,22,36,18,27};
	printf("sizeof(sum)=%d\n",(int)sizeof(sum));//12
	for(int i=0; i<5; i++)
	{
		bool b = sol.hasPathSum(tree,sum[i]);
		if(b)
			printf("%d is in the pathSum of tree.\n",sum[i]);
		else
			printf("%d is not in the pathSum of tree.\n",sum[i]);

	}

	return 0;
}
