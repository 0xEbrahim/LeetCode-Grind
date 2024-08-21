class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
        for(int i = n - 1 ; ~i ; i--){
            for(int j = 0 ; j < n ; j++){
                if(i >= j){
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
        for(int i = n - 1 ; ~i ; i--){
            for(int j = 0 ; j < n ; j++){
                if(i > j) {dp[i][j] = 0; continue;}
                if(i == j){dp[i][j] = 1; continue;}
                dp[i][j] +=  dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][ j - 1 ];
            }
        }
        return dp[0][n - 1];
    }
};