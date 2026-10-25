class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<int>> next(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    next[j1][j2] = grid[n - 1][j1];
                } else {
                    next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = 0;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int val = 0;
                            if (j1 == j2) {
                                val = grid[i][j1];
                            } else {
                                val = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + dj1 >= 0 && j1 + dj1 < m &&
                                j2 + dj2 >= 0 && j2 + dj2 < m) {
                                val += next[j1 + dj1][j2 + dj2];
                            } else {
                                val += -1e9;
                            }
                            maxi = max(maxi, val);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            next = curr;
        }
        return next[0][m - 1];
    }
};