class Solution {
public:
vector<vector<int>>dp, path;
int n, m;
    bool valid(int i , int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int go(int i , int j){
        if(!valid(i , j)) return 1e5;
        if(i == n - 1 && j == m - 1)
            return path[i][j];
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        ret = INT_MAX;
        ret = min(ret, go(i + 1, j) + path[i][j]);
        ret = min(ret, go(i , j + 1) + path[i][j]);
        return ret;
    }
    int minPathSum(vector<vector<int>>& grid) {
        path = grid;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return go(0 , 0);
    }
};