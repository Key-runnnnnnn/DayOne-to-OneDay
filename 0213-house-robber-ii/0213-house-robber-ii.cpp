class Solution {
private:
    int f(vector<int>& nums, int start, int end) {
        int prev = 0;
        int prev2 = 0;
        for (int i = start; i <= end; i++) {
            int t = nums[i] + prev2;
            int nt = prev;
            int curr = max(t, nt);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int x = f(nums, 0, n - 2);
        int y = f(nums, 1, n - 1);
        return max(x, y);
    }
};