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
    void inorder(TreeNode* root, int& cnt, int& ans, int k) {
        if (!root || cnt >= k) {
            return;
        }
        inorder(root->left, cnt, ans, k);
        if (cnt >= k) {
            return;
        }
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, cnt, ans, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        inorder(root, cnt, ans, k);
        return ans;
    }
};