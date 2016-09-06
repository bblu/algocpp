// Source :
// Author : bblu
// Data : 2016-09-06
//
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

// Defination for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) { }
};
void print(vector<int> &post){
    string result3 ;
    for(int i=0; i<post.size(); i++){
        result3 += to_string(post[i])+",";
    }
    printf("result = %s\n",result3.c_str());
}

class Solution {
public:
    
    string getTreePaths(TreeNode* root)
    {
        string order;
        if(root==NULL)
        return order;
        order += '{';
        postOrder(root,order);
        order.pop_back();
        order.push_back('}');
        return order;
    }
    string preOrderReverse(TreeNode* root){
        vector<int> vals;
        vector<TreeNode*> stack;

        if(root) stack.push_back(root);

        while(stack.size()){
            TreeNode* node = stack.back();
            stack.pop_back();
            vals.push_back(node->val);

            if(node->left){
                stack.push_back(node->left);
            }
            if(node->right){
                stack.push_back(node->right);
            }
        }
        std::reverse(vals.begin(),vals.end());
        string str="{";
        for(int i=0; i<vals.size(); i++){
            str += to_string(vals[i])+",";
        }
        str.pop_back();
        str.push_back('}');
        return str;
    }

    void postOrder(TreeNode* node,string& order){
        if(node==NULL)return;
        if(node->left || node->right){
            postOrder(node->left,order);
            postOrder(node->right,order);
        }
        if(node)
            order+=to_string(node->val) +',';
    }   
    vector<int> prostOrderStack(TreeNode* root){
        vector<int> vals;
        vector<TreeNode*> stack;
        TreeNode *node = root;
        TreeNode *lastVisitNode = NULL;

        if(root) stack.push_back(root);
        while(stack.size() || node){
            if(node){
                stack.push_back(node);
                node = node->left;
            }else{
                TreeNode *n = stack.back();
                if(n->right && lastVisitNode != n->right){
                    node = n->right;
                }else{
                    stack.pop_back();
                    vals.push_back(n->val);
                    print(vals);
                    lastVisitNode = n;
                }
            }
        }
        return vals;
    } 
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right =new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    string result = sol.getTreePaths(root); 
    printf("postOrder result = %s\n",result.c_str());

    string result2 = sol.preOrderReverse(root);
    printf("postOrder2 result = %s\n",result2.c_str());

    vector<int> post = sol.prostOrderStack(root);

    string result3 ;
    for(int i=0; i<post.size(); i++){
        result3 += to_string(post[i])+",";
    }
    printf("postOrder3 result = %s\n",result3.c_str());

    return 0;
}
