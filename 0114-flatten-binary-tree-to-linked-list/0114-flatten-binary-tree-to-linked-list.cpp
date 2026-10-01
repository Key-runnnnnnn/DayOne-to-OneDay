/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root) return;
        nodes.push_back(root);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preorder(root,nodes);
        int n= nodes.size();
        if (n == 0) return;
        for(int i = 0;i<n-1;i++){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
        nodes[n-1]->left = nullptr;
        nodes[n-1]->right = nullptr;
    }
};