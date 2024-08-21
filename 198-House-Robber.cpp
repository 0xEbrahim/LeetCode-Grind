class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n + 2, 0);
        for(int i = n - 1; ~i ; i--){
            dp[i] = dp[i + 1];
            dp[i] = max(dp[i], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }
};