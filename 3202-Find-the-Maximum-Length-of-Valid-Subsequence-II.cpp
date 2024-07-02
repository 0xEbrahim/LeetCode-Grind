class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
       int ans = 0;
        vector<vector<int>>dp(n + 1 , vector<int>(k + 1, 1));
       for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < i ; j++){
            int rem = (nums[i] + nums[j]) % k ;
            dp[i][rem] = 1 + dp[j][rem];
        }
       }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < k  ;j++){
            ans = max(ans, dp[i][j]);
        }
    }
       return ans;  
    }
};