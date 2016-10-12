
/*
101. Symmetric Tree
difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return symmetric(root->left, root->right);
    }
    
    bool symmetric(TreeNode* left,TreeNode* right){
        if(left && right){
            return left->val==right->val && 
			symmetric(left->left,right->right) && 
			symmetric(left->right, right->left);
        }
        if(!left && !right)
            return true;
        return false;
    }
};
