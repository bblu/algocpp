// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : bblu
// Date   : 2016-09-02
/****************************************
104. Maximum Depth of Binary Tree
Total Accepted: 172179 
Total Submissions: 348836 
Difficulty: Easy
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest 
path from the root node down to the farthest leaf node.
****************************************/

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
    int maxDepth(TreeNode* root) {
        int dep=0;
        if(root==NULL)
            return dep;
        dep++;
        depth(root,dep);
        return dep;
    }
    
    void depth(TreeNode* node,int& dep){
    
        if(node->left==NULL && node->right==NULL)
            return;
        
        if(node->left || node->right){
            int l=1,r=1;
            if(node->left) depth(node->left,l);
            if(node->right)depth(node->right,r);
            dep+=max(l,r);
        }
    }
	int maxDepth2(TreeNode *root) {
        if (root==NULL) return 0;
        
        if (!root->left && !root->right){
            return 1;
        }
        int left=1, right=1;
        if (root->left){
            left += maxDepth(root->left);
        }
        if (root->right){
            right += maxDepth(root->right);
        }
        return left>right?left:right;
    }
    
};
