class Solution {
public:
    vector<int>dp, value;
    int n ;
    int go(int i){
        if(i >= n)
            return 0;
        int &ret = dp[i];
        if(~ret)
            return ret;
        ret = INT_MAX;
        ret = min(ret, go(i + 1) + value[i]);
        ret = min(ret, go(i + 2) + value[i]);
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        value = cost;
        dp.resize(n + 1 , -1);
        return min(go(0), go(1));
    }
};