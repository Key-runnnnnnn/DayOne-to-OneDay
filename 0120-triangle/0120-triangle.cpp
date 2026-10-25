
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int down = dp[i + 1][j];
                int rightD = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, rightD);
            }
        }
        return dp[0][0];
    }
};
