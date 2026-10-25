class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        for (int j = 0; j < m; j++) {
            dp[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            int diagonalLeft = INT_MAX;
            for (int j = 0; j < m; j++) {
                int up = dp[j];
                int leftD = diagonalLeft;
                int rightD = (j < m - 1) ? dp[j + 1] : INT_MAX;
                dp[j] = matrix[i][j] + min({up, leftD, rightD});
                diagonalLeft = up;
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[j]);
        }
        return mini;
    }
};