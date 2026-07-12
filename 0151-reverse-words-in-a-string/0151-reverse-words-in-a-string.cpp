class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string token = "";
        stringstream ss(s);
        while(ss >> token){
            result = token+" "+result;
        }
        return result.substr(0,result.size()-1);
    }
};