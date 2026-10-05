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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int preStart, int preEnd, int inStart, int inEnd,
                        map<int, int>& hash) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = hash[root->val];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder, inorder, preStart + 1,
                               preStart + numsLeft, inStart, inRoot - 1, hash);

        root->right = buildTree(preorder, inorder, preStart + numsLeft + 1,
                                preEnd, inRoot + 1, inEnd, hash);
                                
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;

        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1, hash);
    }
};