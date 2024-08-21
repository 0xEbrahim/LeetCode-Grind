class Solution {
public:
    int go(vector<int>&dp, vector<int>&coins, int target){
        if(target < 0) return 1e6;
        if(target == 0) return 0;
        int &ret = dp[target];
        if(~ret) return ret;
        ret = INT_MAX;
        for(int i = 0 ; i < coins.size() ; i++){
            ret = min(ret, 1 + go(dp, coins, target - coins[i]));
        }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount + 1, -1);
       return go(dp, coins, amount) >= 1e6 ? -1 : go(dp, coins, amount);
    }
};