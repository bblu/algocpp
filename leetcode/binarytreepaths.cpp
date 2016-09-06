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

class Solution {
public:
    vector<string> treePaths;
    
    vector<string> getTreePaths(TreeNode* root)
    {
        if(root==NULL)
            return treePaths;
        string path="root";
        //path+=(char)(root->val+'0');
        searchPath(root, path);
        return treePaths;
    }

    void searchPath(TreeNode* node, string path)
    {
        path += "->" + to_string(node->val);
        if(node->left==NULL && node->right==NULL) {
            printf("path = %s\n",path.c_str());
            treePaths.push_back(path);
            return;
        } else {
            if(node->left)
                searchPath(node->left, path);
            if(node->right)
                searchPath(node->right,path);
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =new TreeNode(3);

    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> result = sol.getTreePaths(root); 

    return 0;
}
