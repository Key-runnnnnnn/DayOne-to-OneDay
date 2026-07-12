class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string str = "";
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (cnt != 0)
                    str += ch;
                cnt++;
            } else {
                cnt--;
                if (cnt != 0)
                    str += ch;
            }
        }
        return str;
    }
};