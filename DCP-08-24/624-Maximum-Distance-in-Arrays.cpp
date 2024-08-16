const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<pair<int, int>>mins(n), maxs(n);
        for(int i = 0 ; i < n ; i++){
            mins[i] = {1e5, i };
            maxs[i] = {-1e5, i};
            for(int j = 0 ; j < v[i].size() ; j++){
                mins[i] = { min(mins[i].first, v[i][j]) , i };
                maxs[i] = { max(maxs[i].first, v[i][j]), i };
            }
        }
    int ret1 = -1e5, ret2 = -1e5;
    sort(mins.begin(), mins.end());
    sort(maxs.rbegin(), maxs.rend());
    int l1 = 0, l2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(mins[0].second != maxs[i].second){
            ret1 = max(ret1, abs(mins[0].first - maxs[i].first));
        }
        if(mins[i].second != maxs[0].second){
            ret2 = max(ret2, abs(mins[i].first - maxs[0].first));
        }
    }
    return max(ret1, ret2);
    }   
};