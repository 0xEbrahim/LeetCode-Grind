class Solution {
public:
    int dp[101][2];
    int n;
    vector<int>v;
    int go(int idx, bool took){
        if(idx >= n) return 0;
        if(took && idx == n - 1) return 0;
        int &ret = dp[idx][took];
        if(~ret) return ret;
        ret = go(idx + 1, took);
        if(idx == 0) ret = max(ret, go(idx + 2, true) + v[idx]);
        else ret = max(ret, go(idx + 2, took) + v[idx]);
        return ret;
    }
    int rob(vector<int>& nums) {
         n = nums.size();
         v = nums;
        memset(dp, -1, sizeof dp);
        return go(0, false);
    }
};