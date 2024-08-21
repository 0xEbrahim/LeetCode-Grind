const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(n + 1, 0));
        for(int i = 0 ; i < n ; i++)
            dp[i][i] = true;
        for(int i = n - 1 ; ~i ; i--){
            for(int j = 0 ; j < n ; j++){
                if(i >= j){
                    dp[i][j] = true;
                    continue;
                }
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        int l = 0 , r = 0, mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(dp[i][j] == 1){
                    if(j - i + 1 > mx){
                        mx = j - i + 1;
                        l = i;
                        r = j;
                    }
                }
            }
        }
        string ret = "";
        for(int i = l ; i <= r ; i++) ret += s[i]; 
        return ret;
    }
};