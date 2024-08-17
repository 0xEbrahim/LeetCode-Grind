const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
long long maxPoints(vector<vector<int>>& points) {
       int n = (int)points.size();
       int m = (int)points[0].size();
        vector<long long>row;
        for(int i = 0 ; i < m ; i++)
            row.push_back(points[0][i]);
        for(int i = 1 ; i < n ; i++){
            vector<long long>next_row;
            for(int j = 0 ; j < m ; j++)
                next_row.push_back((long long)(points[i][j]));
            vector<long long>left(m), right(m);
            left[0] = row[0];
            for(int j = 1 ; j < m ; j++){
                left[j] = max(left[j - 1] - 1, row[j]);
            }
            right[m - 1] = row[m - 1];
            for(int j = m - 2 ; ~j ; j--){
                right[j] = max(right[j + 1] - 1, left[j]);
            }
            for(int j = 0 ; j < m ; j++)
                next_row[j] += max(left[j], right[j]);
            row = next_row; 
        }
        long long ret = -1e17;
        for(int i = 0 ; i < m ; i++)
            ret = max(ret, row[i]);
        return ret;
    }
};