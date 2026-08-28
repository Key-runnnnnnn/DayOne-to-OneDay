class Solution {
private:
    void f(int ind, int sum, vector<vector<int>> &ans, vector<int>& arr, int target,
           vector<int>& temp, int n) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (ind >= n || sum>target) {
            return;
        }
        temp.push_back(arr[ind]);
        f(ind, sum + arr[ind], ans, arr, target, temp, n);
        temp.pop_back();
        f(ind + 1, sum, ans, arr, target, temp, n);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        f(0, 0, ans, candidates, target, temp, n);
        return ans;
    }
};