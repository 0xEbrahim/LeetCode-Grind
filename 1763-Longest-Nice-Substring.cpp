class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        string ret;
        int mx_len = 0;
        for(int i = 0 ; i < s.size() ; i++){
            bool up[26] = {};
            bool low[26] ={};
            for(int j = i ; j < s.size() ; j++){
                if(isupper(s[j])) up[s[j] - 'A'] = true;
                else low[s[j] - 'a'] = true;
                int len = j - i + 1;
                if(len > mx_len){
                    int k = 0;
                    for(; k < 26 ; k++){
                        if(up[k] != low[k]) break;
                    }
                    if(k == 26){
                        mx_len = len;
                        ret = s.substr(i, mx_len);
                    }
                }
            }
        }
        if(mx_len == 0) return "";
        return ret;
    }
};