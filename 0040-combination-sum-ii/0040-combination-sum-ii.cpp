class Solution {
private:
    void f(int ind, vector<int>& arr, vector<vector<int>>& ans, int target,
           vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            temp.push_back(arr[i]);
            f(i + 1, arr, ans, target - arr[i], temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        f(0, candidates, ans, target, temp);
        return ans;
    }
};