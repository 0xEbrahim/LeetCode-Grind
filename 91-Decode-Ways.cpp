#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int>dp;
    int go(int i, string&s){
        if(i == s.size()) return 1;
        int &ret = dp[i];
        if(~ret)
            return ret;
        ret = 0;
        if(s[i] != '0')
            ret += go(i + 1, s);
        string cur = "";
        cur += s[i];
        if(cur != "0" && i + 1 < s.size()){
            cur += s[i + 1];
            int x = stoll(cur);
            if(x < 27)
                ret += go(i + 2, s);
        }
        return ret;
    }
   int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return go(0, s);
    }
};