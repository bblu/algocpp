#include <stdlib.h>
#include <stdio.h>
#include <vector>

//Defination for binary tree

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
public:
    bool isBalanced(TreeNode *root){
        int height;
        return isBalancedUtil(root, height);
    }

    bool isBalancedUtil(TreeNode *root, int& height){
        if(root == NULL){
            height = 0;
            printf("h=%d  node is NULL\n" ,height);
            return true;
        }
        int lh=0, rh=0;
        bool isLeft = isBalancedUtil(root->left,lh);
        bool isRight= isBalancedUtil(root->right,rh);
        height = (lh>rh ? lh : rh) + 1;
        printf("val=%d,height=%d, left=%d, right=%d\n",root->val, height, lh, rh);
        return (abs(lh-rh) <= 1 && isLeft && isRight);
    }
};

int main(){

    TreeNode* l = new TreeNode(2);
    l->left  = new TreeNode(4);
    l->right = new TreeNode(5);
    l->left->right = new TreeNode(9);

    TreeNode* r = new TreeNode(3);
    r->left  = new TreeNode(6);
    r->right = new TreeNode(7);

    TreeNode* root  = new TreeNode(1);
    root->left  = l;
    root->right = r;

    Solution sol;

    bool b = sol.isBalanced(root);

    return 0;
};


