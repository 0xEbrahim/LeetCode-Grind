class Solution {
public:
    int n;
    vector<string>grid;
set<vector<string>>ans;
bool up(int i , int j, vector<string> &v){
    bool can = true;
    for(i = i - 1 ; ~i ; i--)
        can &= v[i][j] != 'Q';
    return can;
}
bool down(int i , int j, vector<string> &v){
    bool can = true;
    for(i = i + 1 ; i < n ; i++)
        can &= v[i][j] != 'Q';
    return can;
}
bool left(int i , int j, vector<string> &v){
    bool can = true;
    for(j  = j - 1 ; ~j ; j--)
        can &= v[i][j] != 'Q';
    return can;
}
bool right(int i , int j , vector<string> &v){
    bool can = true;
    for(j = j + 1 ; j < n ; j++)
        can &= v[i][j] != 'Q';
    return can;
}
bool diag_up(int i , int j, vector<string> &v){
    bool can = true;
    int k = i , l = j;
    i--;
    j--;
    while(i >= 0 && j >= 0){
        can &= v[i][j] != 'Q';
        i--;
        j--;
    }
    k--;
    l++;
    while(k >= 0 && l < n){
        can &= v[k][l] != 'Q';
        k--;
        l++;
    }
    return can;
}
bool diag_down(int i , int j, vector<string> &v){
    bool can = true;
    int k = i , l = j;
    i++;
    j--;
    while(i < n && j >= 0){
        can &= (v[i][j] != 'Q');
        i++;
        j--;
    }
    k++;
    l++;
    while(k < n && l < n){
        can &= v[k][l] != 'Q';
        k++;
        l++;
    }
    return can;
}

bool valid_place(int i , int j, vector<string> &v){
    return (v[i][j] != 'Q' && up(i , j,v) && down(i , j,v) && left(i , j,v) && right(i, j,v) && diag_down(i , j,v) && diag_up(i , j,v));
}
bool check_validity(int i , int j , vector<string>&v){
    return (up(i , j,v) && down(i , j,v) && left(i , j,v) && right(i, j,v) && diag_down(i , j,v) && diag_up(i , j,v));
}
bool valid_grid(vector<string>&s){
    bool can = true;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s[i][j] == 'Q')
                can &= check_validity(i,j,s);
        }
    }
    return can;
}
void go(int i, int count = 0, vector<string> game = {}){
    if(count == n){
        if(valid_grid(game))
            ans.insert(game);
        return;
    }
    if(count > n)
        return;
       for(int col = 0 ; col < n ; col++){
        if(valid_place(i,col,game)){
            game[i][col] = 'Q';
            go(i + 1, count+1, game);
            game[i][col] = '.';
        }
       }
    }
    vector<vector<string>> solveNQueens(int x) {
        n = x;
         grid.resize(n);
    for(int i = 0 ; i < n ; i++){
        string tmp = \\;
        for(int j = 0 ; j < n ; j++)
            tmp += '.';
        grid[i] = tmp;
    }
    go(0,0,grid);
    vector<vector<string>>xx;
    for(auto &it : ans)
        xx.push_back(it);
    return xx;
    }
};