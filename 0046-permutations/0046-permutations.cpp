class Solution {
private:
    void f(vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums,
           vector<bool> &mp) {
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i]==false){
                temp.push_back(nums[i]);
                mp[i]=1;
                f(temp,ans,nums,mp);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> mp(nums.size(), false);
        f(temp, ans, nums, mp);
        return ans;
    }
};