class Solution {
private:
    void f(int ind, vector<int> &temp, vector<int>& nums, vector<vector<int>> &ans){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        f(ind+1,temp,nums,ans);
        temp.pop_back();
        f(ind+1,temp,nums,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,temp,nums,ans);
        return ans;
    }
};