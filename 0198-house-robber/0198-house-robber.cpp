class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for (int i = 2; i <= n; i++) {
            int np = prev;
            int p = nums[i - 1] + prev2;
            int curr = max(p, np);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
