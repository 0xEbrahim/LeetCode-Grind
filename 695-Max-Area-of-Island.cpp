class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1}; 
    int cnt = 0;
    void dfs(int i , int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j])
            return;
        vis[i][j] = true;
        cnt++;
        for(int k = 0 ; k < 4 ; k++)
            dfs(i + dx[k], j + dy[k], grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0 ; i < grid.size() ; i++) for(int j = 0 ; j < grid[0].size() ; j++) if(grid[i][j] == 1 && !vis[i][j]) cnt = 0, dfs(i, j, grid, vis), ans = max(ans, cnt);
        return ans;
    }
};