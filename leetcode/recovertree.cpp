/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // referance haoel @ 2016-08-21
class Solution {
public:
    void recoverTree(TreeNode* root) {
        n1=n2=prev=NULL;
        treeSearch(root);
        if(n1 && n2){
            swap(n1->val,n2->val);
        }
    } 
    void treeSearch(TreeNode *root){
        if(root == NULL)
            return;
        treeSearch(root->left);
        if(prev){
            if(prev->val > root->val){
                if(n1==NULL)n1=prev;
                n2=root;
            }
        }
        prev = root;
        treeSearch(root->right);
    }
private:
    TreeNode *n1,*n2,*prev;
};
