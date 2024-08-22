class Solution {
public:
   int dp[301];
int go(int i, string &s, unordered_set<string>&st){
    if(i == s.size()) return 1;
    int &ret = dp[i];
    if(~ret) return ret;
    for(int j = i ; j < s.size() ; j++){
        if(st.count(s.substr(i, j - i + 1)) && go(j + 1, s , st)){
            return ret = 1;
        }
    }
    return ret = 0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return go(0,s,st);
    }
};