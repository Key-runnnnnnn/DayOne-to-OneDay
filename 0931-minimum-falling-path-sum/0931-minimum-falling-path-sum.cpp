class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0), curr(m, 0);
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = INT_MAX, leftD = INT_MAX, rightD = INT_MAX;
                if (i > 0) {
                    up = matrix[i][j] + prev[j];
                }
                if (i > 0 && j > 0) {
                    leftD = matrix[i][j] + prev[j - 1];
                }
                if (i > 0 && j < m - 1) {
                    rightD = matrix[i][j] + prev[j + 1];
                }
                curr[j] = min({up, leftD, rightD});
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};