const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int maxDistance(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<pair<int, int>>mins(n), maxs(n);
        pair<int, int> mn, mx;
        mn = {1e5 + 1, 0};
        mx = {-1e6 + 1, 0};
        for(int i = 0 ; i < n ; i++){
            mins[i] = {1e5, i };
            maxs[i] = {-1e5, i};
            for(int j = 0 ; j < v[i].size() ; j++){
                mins[i] = { min(mins[i].first, v[i][j]) , i };
                maxs[i] = { max(maxs[i].first, v[i][j]), i };
                if(mins[i].first < mn.first)
                    mn = mins[i];
                if(maxs[i].first > mx.first)
                    mx = maxs[i];
            }
        }
    int ret1 = -1e5, ret2 = -1e5;
    int l1 = 0, l2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(mn.second != maxs[i].second){
            ret1 = max(ret1, abs(mn.first - maxs[i].first));
        }
        if(mins[i].second != mx.second){
            ret2 = max(ret2, abs(mins[i].first - mx.first));
        }
    }
    return max(ret1, ret2);
    }   
};