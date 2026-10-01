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
    void parent_mapping(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parent_track,
                        TreeNode*& startNode, int start) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            if (current->val == start) {
                startNode = current;
            }
            q.pop();
            if (current->left) {
                q.push(current->left);
                parent_track[current->left] = current;
            }
            if (current->right) {
                q.push(current->right);
                parent_track[current->right] = current;
            }
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* startNode;
        parent_mapping(root, parent_track, startNode, start);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = true;
        int time = 0;
        while (!q.empty()) {
            bool infected = false;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left && !vis[current->left]) {
                    q.push(current->left);
                    vis[current->left] = true;
                    infected = true;
                }
                if (current->right && !vis[current->right]) {
                    q.push(current->right);
                    vis[current->right] = true;
                    infected = true;
                }
                if (parent_track[current] && !vis[parent_track[current]]) {
                    q.push(parent_track[current]);
                    vis[parent_track[current]] = true;
                    infected = true;
                }
            }
            if (infected) {
                time++;
            }
        }

        return time;
    }
};