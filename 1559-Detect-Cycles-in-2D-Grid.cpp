class Solution {
public:
    int n , m ;
char cur;
int dx[4] = {1, -1, 0, 0},
        dy[4] = {0, 0, 1, -1};
vector<vector<char>>v;
bool vis[512][512] = {};
bool valid(int i , int j){
    return i < n && i >= 0 && j < m && j >= 0 && v[i][j] == cur ;
}
bool detect(int i_nd, int j_nd, int i_par, int j_par){
    vis[i_nd][j_nd] = true;
    for(int i = 0 ; i < 4 ; i++){
        int i_child = i_nd + dx[i];
        int j_child = j_nd + dy[i];
        if(valid(i_child, j_child) && !vis[i_child][j_child]){
            if(detect(i_child, j_child, i_nd, j_nd))
                return true;
        }else if(valid(i_child, j_child) && i_child != i_par && j_child != j_par)
            return true;
    }
    return false;
}
bool containsCycle(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    v = grid;
    bool cycle = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j]){
                cur = v[i][j];
                cycle |= detect(i,j,-1,-1);
            }
        }
    }
    return cycle;
}
};
