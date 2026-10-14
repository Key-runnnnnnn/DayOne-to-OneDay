/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* f(vector<int>& preorder, int& ind, int bound) {
        if (ind == preorder.size() || preorder[ind] > bound)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = f(preorder, ind, root->val);
        root->right = f(preorder, ind, bound);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(preorder, i, INT_MAX);
    }
};