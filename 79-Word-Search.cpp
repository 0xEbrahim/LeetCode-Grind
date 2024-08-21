 const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int n , m ;
    bool ret;
    void backtrack(int i , int j, vector<vector<char>>&grid, string&word, string s){
        if(s.size() > word.size()) return;
        if(s.size() && s[s.size() - 1] != word[s.size() - 1]) return;
        if(s == word) {
            ret = true;
            return;
        }
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#') return;
        char org = grid[i][j];
        grid[i][j] = '#';
        s += org;
        backtrack(i - 1, j, grid, word, s);
        backtrack(i + 1, j, grid, word, s);
        backtrack(i, j - 1, grid, word, s);
        backtrack(i, j + 1, grid, word, s);
        grid[i][j] = org;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        string s = "";
        ret = false;
        for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) if(!ret) backtrack(i,j,board, word, s);
        return ret;
    }
};