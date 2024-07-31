class Solution {
public:
    int go(int i, int w, int h, int mx, vector<vector<int>>&v, vector<vector<int>>&dp){
    if(i >= v.size())
        return h;
    int&ret = dp[i][w];
    if(~ret)
        return ret;
    ret = h + go(i + 1, v[i][0], v[i][1], mx, v, dp);
    if(w + v[i][0] <= mx)
        ret = min(ret, go(i + 1, w + v[i][0], max(h, v[i][1]), mx, v, dp));
    return ret;
}
int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<vector<int>>dp(n + 1, vector<int>(shelfWidth + 10, -1));
    return go(0,0,0,shelfWidth,books,dp);
}
};