class Solution {
public:
int n , m ;
vector<vector<int>>v;
int dp[71][71][71];
bool valid(int i , int j){
    return i >= 0 && i < n && j >= 0 && j < m ;
}
int solve(int i , int j , int r){
    if(!valid(i, j) || !valid(i , r))
        return 0;
    int &ret = dp[i][j][r];
    if(~ret)
        return ret;
    int op1 = 0 , op2 = 0 , op3 = 0 , op4 = 0 , op5 = 0 , op6 = 0, op7 = 0 , op8 = 0, op9 = 0;
    if(j == r){
    op1 = max(solve(i + 1,  j - 1,  r - 1) +  v[i][j] ,solve(i + 1,  j - 1,  r - 1) + v[i][r]);
    op2 = max(solve(i + 1,  j - 1,   r)     +       v[i][j] ,solve(i + 1,  j - 1,   r) +  v[i][r]);
    op3 = max(solve(i + 1,  j - 1,   r + 1) +     v[i][j] , solve(i + 1,  j - 1,   r + 1) + v[i][r]);
    op4 = max(solve(i + 1,  j,        r - 1) +    v[i][j] , solve(i + 1,  j,       r - 1) + v[i][r]);
    op5 = max(solve(i + 1,  j,       r)     +         v[i][j] , solve(i + 1,  j,       r) + v[i][r]);
    op6 = max(solve(i + 1,  j,        r + 1) +    v[i][j] ,solve(i + 1,  j,        r + 1) + v[i][r]);
    op7 = max(solve(i + 1,  j + 1,   r - 1) +    v[i][j] , solve(i + 1,  j + 1,    r - 1) +  v[i][r]);
    op8 = max(solve(i + 1,  j + 1,    r)     +         v[i][j] ,solve(i + 1,  j + 1,   r)     +  v[i][r]);
    op9 = max(solve(i + 1,  j + 1,   r + 1) +    v[i][j] ,solve(i + 1,  j + 1,  r + 1) + v[i][r]);
    }else{
    op1 = solve(i + 1,  j - 1,   r - 1) +    v[i][j] + v[i][r];
    op2 = solve(i + 1,  j - 1,   r)     +       v[i][j] + v[i][r];
    op3 = solve(i + 1,  j - 1,  r + 1) +     v[i][j] + v[i][r];
    op4 = solve(i + 1,  j,        r - 1) +    v[i][j] + v[i][r];
    op5 = solve(i + 1,  j,        r)     +         v[i][j] + v[i][r];
    op6 = solve(i + 1,  j,       r + 1) +    v[i][j] + v[i][r];
    op7 = solve(i + 1,  j + 1,    r - 1) +    v[i][j] + v[i][r];
    op8 = solve(i + 1,  j + 1,   r)     +         v[i][j] + v[i][r];
    op9 = solve(i + 1,  j + 1,    r + 1) +    v[i][j] + v[i][r];
    }
    return ret = max({op1, op2 , op3 , op4 , op5 , op6 , op7, op8, op9});
}
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        v = grid;
        memset(dp, -1, sizeof dp);
        return solve(0,0,m-1);
    }
};