
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
		
	}
// 34 test cases 9ms
    vector<vector<int> > levelOrder2(TreeNode* root) {
        vector<vector<int> > result;
        queue<TreeNode*> level;
        level.push(root);
        getLevel(level, result, 0);
        
        return result;
    }
    
    void getLevel(queue<TreeNode*> level,vector<vector<int> > &result,int height){
			if(level.empty()) return;
        	queue<TreeNode*> subLevel;
			vector<int> subv;
			while(level.size()){
				TreeNode *node = level.front();
				level.pop();
				subv.push_back(node->val);
				if(node->left) subLevel.push(node->left);
				if(node->right) subLevel.push(node->right);
			}
			cout << "height = " << height << " subSize = "<< subLevel.size() << endl;
			if(!subv.empty()){
				result.push_back(subv);
			}
			getLevel(subLevel,result,height+1);
    }
};

int main(){
	TreeNode* root=new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right= new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right= new TreeNode(7);
	Solution sol;
	vector<vector<int> > result = sol.levelOrder(root);

	for(int i=0; i<result.size(); i++){
		cout <<  "[";
		for(int j=0; j<result[i].size(); j++){
			cout << result[i][j] <<", ";
		}
		cout << "]," << endl;
	}
	return 0;
}
