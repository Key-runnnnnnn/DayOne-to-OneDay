/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        queue<TreeNode*> q;
        markParent(root, parent_track);
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;
        int level = 0;
        while (!q.empty() && level<k) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (parent_track[node] && !vis[parent_track[node]]) {
                    q.push(parent_track[node]);
                    vis[parent_track[node]] = true;
                }
            }
        }
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};