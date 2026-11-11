
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        curr[0] = 1;
        if (nums[0] <= target) {
            prev[nums[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int tar = 1; tar <= target; tar++) {
                bool notTake = prev[tar];
                bool take = false;
                if (nums[i] <= tar) {
                    take = prev[tar - nums[i]];
                }
                curr[tar] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};
