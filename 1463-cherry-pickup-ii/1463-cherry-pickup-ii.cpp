class Solution {
private:
    int f(int i, int j1, int j2, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int m = grid[0].size();
        int n = grid.size();
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e9;
        }
        if (i == n - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if (j1 == j2) {
                    val = grid[i][j1];
                } else {
                    val = grid[i][j1] + grid[i][j2];
                }
                val += f(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp);
    }
};