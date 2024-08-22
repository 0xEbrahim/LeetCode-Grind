class Solution {
public:
    struct P{
        int x, y , steps;
    };
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool check(vector<vector<bool>>&vis, vector<vector<int>>&grid){
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return false;
            }
        }
        return true;
    }
    bool valid(int i , int j, int n , int m, vector<vector<int>>&grid){
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<P>q;
        bool one = false;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                one |= grid[i][j] == 1;
                if(grid[i][j] == 2) q.push({i, j, 0}),vis[i][j] = true ;
            }
        }
        int ans = !one ? 0 : (-1);
        while(not q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();
            if(check(vis, grid))
             ans = max(steps, ans);
            for(int i = 0 ; i < 4 ; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(valid(X, Y, n , m, grid) && !vis[X][Y]){
                    vis[X][Y] = true;
                    q.push({X, Y, steps + 1});
                }
            }
        }
        return ans;   
    }
};