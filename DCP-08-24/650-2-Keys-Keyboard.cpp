class Solution {
public:
vector<vector<int>>dp;
int num;
int go(int cur, int copied){
    if(cur > num || copied > num)
        return 1e6;
    if(cur == num)
        return 0;
    int &ret = dp[cur][copied];
    if(~ret)
        return ret;
    ret = 1e7;
    ret = min(ret, go(cur, cur) + 1);
    ret = min(ret, go(cur + copied, copied) + 1);
    return ret;
}
    int minSteps(int n) {
        num = n;
        dp.resize(2 * n + 10, vector<int>(2 * n + 10, -1));
        return go(1,0);
    }
};