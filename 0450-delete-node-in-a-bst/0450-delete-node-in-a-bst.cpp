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
    TreeNode* f(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = lastRightNode(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* lastRightNode(TreeNode* root){
        if(!root->right){
            return root;
        }
        return lastRightNode(root->right);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            return f(root);
        }
        TreeNode* curr = root;
        while (curr) {
            if (curr->val > key) {
                if (curr->left && curr->left->val == key) {
                    curr->left = f(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = f(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};