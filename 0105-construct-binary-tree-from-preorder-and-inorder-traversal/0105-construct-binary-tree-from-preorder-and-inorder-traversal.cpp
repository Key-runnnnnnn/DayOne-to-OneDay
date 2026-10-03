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
        // No elements to construct
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root in inorder
        int inRoot = hash[root->val];

        // Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = buildTree(preorder, inorder, preStart + 1,
                               preStart + numsLeft, inStart, inRoot - 1, hash);

        // Build right subtree
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