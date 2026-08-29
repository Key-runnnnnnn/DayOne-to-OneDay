class Solution {
private:
    void f(int ind,  vector<vector<int>> &ans,  vector<int> &temp, vector<int>& nums){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            f(i+1,ans, temp,nums);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,ans,temp,nums);
        return ans;        
    }
};