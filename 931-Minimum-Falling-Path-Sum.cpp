const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    vector<vector<int>>dp;
int n , m ;
bool valid(int i , int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}
int dy[3] = {-1,0,1};
int go(int i , int j,vector<vector<int>>&grid){
    if(!valid(i , j))
            return 1e5;
    if(i == n - 1)
        return grid[i][j];
    int &ret = dp[i][j];
    if(ret != -1000000)
        return ret;
    ret = 1e6;
    for(int k = 0 ; k < 3 ; k++){
        int x = i + 1 ;
        int y = j + dy[k];
        if(valid(x , y)){
            ret = min(ret, grid[i][j] + go(x, y, grid));
            }
    }
    return ret;
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();
    dp.resize(n + 1, vector<int>(m + 1, -1000000));
    int ret = INT_MAX;
    for(int i = 0 ; i < m ; i++)
        ret = min(ret, go(0, i, matrix));
    return ret;
}
};