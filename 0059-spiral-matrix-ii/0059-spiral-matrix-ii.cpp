class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = 0, t = 0, r = n - 1, b = n - 1;
        int x = 1;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) {
                ans[t][i] = x;
                x++;
            }
            t++;
            for (int i = t; i <= b; i++) {
                ans[i][r] = x;
                x++;
            }
            r--;
            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    ans[b][i] = x;
                    x++;
                }
            }
            b--;
            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    ans[i][l] = x;
                    x++;
                }
            }
            l++;
        }
        return ans;
    }
};