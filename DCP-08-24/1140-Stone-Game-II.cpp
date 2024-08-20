class Solution {
public:
    vector<int>v;
int n;
int dp[101][201][2];
int go(int idx, int m, bool turn){
    if(idx == n) return 0;
    int &ret = dp[idx][m][turn];
    if(~ret)
        return ret;
    ret = !turn ? 0 : INT_MAX;
    int tot = 0;
    for(int i = 1 ; i < 2 * m + 1 ; i++){
        if(i + idx > n)
            break;
        tot += v[i + idx - 1];
        if(!turn){
            ret = max(ret, go(i + idx, max(i , m), not turn) + tot);
        }else{
            ret = min(ret, go(idx + i, max(i , m), not turn));
        }
    }
    return ret;
}
    int stoneGameII(vector<int>& piles) {
        v = piles;
        n = v.size();
        memset(dp, -1, sizeof dp);
        return go(0, 1,false);
    }
};