class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int buy = nums[0];
        int profit = 0;
        for(int i=0;i<n;i++){
            buy = min(buy,nums[i]);
            profit = max(profit,nums[i]-buy);
        }
        return profit;
    }
};