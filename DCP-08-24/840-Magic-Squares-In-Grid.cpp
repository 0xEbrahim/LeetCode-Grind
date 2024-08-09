class Solution {
public:
     int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n < 3 || m < 3)
            return 0;
        int ans = 0;
        for(int i = 0  ; i <= n - 3 ; i++){
            for(int j = 0 ; j <= m - 3; j++){
                set<int>dist;
                 vector<int>sums(9);
                 int ii = -1;
                for(int k = i ; k < i + 3 ; k++){
                    ii++;
                    int jj = 1;
                    bool first = false, sec = false, third = false;
                    if(k == i)
                        first = true;
                    if(k == i + 1)
                        sec = true;
                    if(k == i + 2)
                        third = true;
                    for(int l = j ; l < j + 3 ; l++){
                        dist.insert(grid[k][l]);
                        sums[ii] += grid[k][l];
                        if(first){
                            sums[7] += grid[k][j];
                            first = false;
                            sums[8] += grid[k][j + 3 - 1];
                            }
                        if(sec)
                        {
                            sums[7] += grid[k][j + 1];
                            sec = false;
                            sums[8] += grid[k][j + 3 - 2];
                        }
                        if(third){
                            sums[7] += grid[k][j + 2];
                            third = false;
                            sums[8] += grid[k][j + 3 - 3];
                        }
                    }
                }
                int idx = 3;
                for(int l = j ; l < j + 3 ; l++){
                    idx++;
                    for(int k = i ; k < i + 3 ; k++){
                        sums[idx] += grid[k][l];
                    }
                }
                if(dist.size() == 9 && sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[4] && sums[4] == sums[5] && sums[5] == sums[6] && sums[6] == sums[7] && sums[7] == sums[8]){
                    bool x = false;
                    for(auto it : dist){
                        if(it > 9 || it == 0)
                        {
                            x = true;
                            break;
                        }
                    }
                    if(!x)
                        ans++;
                }
            }
        }
        return ans;
    }
};