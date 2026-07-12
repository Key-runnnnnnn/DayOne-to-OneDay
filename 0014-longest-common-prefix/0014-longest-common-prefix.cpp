class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            int match = 1;
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != ch) {
                    match = 0;
                    break;
                }
            }
            if (match == 0) {
                break;
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};