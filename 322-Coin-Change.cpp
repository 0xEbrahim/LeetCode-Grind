class Solution {
public:
    vector<long long>dp,coin;
    int n;
    long long mn;
    long long go(int have){
        if(have == 0){
            return 0;
        }
        if(have < mn)
            return 1e15;
        long long &ret = dp[have];
        if(~ret)
            return ret;
        ret = 1e16;
       for(int i = 0 ; i < n ; i++){
            if(have >= coin[i]){
                ret = min(ret, go(have - coin[i]) + 1);
            }
       }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        coin.resize(n);
        mn = LLONG_MAX;
        for(int i = 0 ; i < n ; i++)
            coin[i] = coins[i], mn = min(mn , coin[i]);
        dp.resize(amount + 1 , -1);
        long long ret = go(amount);
        return (ret >= 1e15 ? -1 : ret);
    }
};