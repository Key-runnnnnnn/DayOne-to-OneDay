
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int tar = 1; tar <= target; tar++) {
                bool notTake = dp[i - 1][tar];
                bool take = false;
                if (nums[i] <= tar) {
                    take = dp[i - 1][tar - nums[i]];
                }
                dp[i][tar] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};
