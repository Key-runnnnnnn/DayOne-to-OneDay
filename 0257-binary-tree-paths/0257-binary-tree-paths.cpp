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
    void f(TreeNode* root, vector<string>& ans, string& s) {
        if (root == nullptr)
            return;
        int len = s.size();
        if (!s.empty()) {
            s += "->";
        }
        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
        } else {
            f(root->left, ans, s);
            f(root->right, ans, s);
        }
        s.resize(len);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        f(root, ans, s);
        return ans;
    }
};