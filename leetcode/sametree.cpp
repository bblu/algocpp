/**********************************************************
100.same Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 150146 Total Submissions: 339226 Difficulty: Easy
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Subscribe to see which companies asked this question
***********************************************************/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q){
            if(p->val == q->val){
                bool chd = isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
                if(!chd)
                    return false;
            }else{
                return false;
            }
        }else if(p || q){
            return false;
        }
        return true;
    }
};

