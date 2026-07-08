class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    a[i][0] = 0;
                    if (j != 0) {
                        a[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] != 0) {
                    if (a[i][0] == 0 || a[0][j] == 0) {
                        a[i][j] = 0;
                    }
                }
            }
        }

        if (a[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                if (a[0][j] != 0) {
                    a[0][j] = 0;
                }
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                if (a[i][0] != 0) {
                    a[i][0] = 0;
                }
            }
        }
    }
};