class Solution {
private:
    void f(int ind, int sum, vector<int>& arr, set<vector<int>>& st, int target,
           vector<int>& temp, int n) {
        if (sum == target) {
            st.insert(temp);
            return;
        }
        if (ind >= n || sum>target) {
            return;
        }
        temp.push_back(arr[ind]);
        f(ind, sum + arr[ind], arr, st, target, temp, n);
        temp.pop_back();
        f(ind + 1, sum, arr, st, target, temp, n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        set<vector<int>> st;
        vector<int> temp;
        f(0, 0, candidates, st, target, temp, n);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};