class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> ans;
        int l = 0, t = 0, r = m - 1, b = n - 1;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++){
                ans.push_back(a[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                ans.push_back(a[i][r]);
            }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    ans.push_back(a[b][i]);
                }
            }
            b--;
            if(l<=r){
                for(int i=b;i>=t;i--){
                    ans.push_back(a[i][l]);
                }
            }
            l++;
        }
        return ans;
    }
};