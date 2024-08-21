class Solution {
public:
int dp[103][103];
string v;
int go(int i , int j){
    if(i == j) return 1;
    int &ret = dp[i][j];
    if(~ret)return ret;
    ret = INT_MAX;
    for(int k = i ; k < j ; k++)
        ret = min(ret, go(i, k) + go(k + 1, j));
    ret -= (v[i] == v[j]);
    return ret;
}
int strangePrinter(string s) {
    v = s;
    memset(dp, -1, sizeof dp);
    return go(0,s.size() - 1);
}
};