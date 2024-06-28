const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>deg(n + 5);
        for(int i = 0 ; i < roads.size() ; i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        vector<pair<long long, long long>>values;
        for(int i = 0 ; i < n ; i++){
            values.push_back({deg[i], i});
        }
        sort(values.rbegin(), values.rend());
        vector<long long>importance(n + 2);
        int val = n;
        for(int i = 0 ; i < n ; i++)
            importance[values[i].second] = val--;
        long long ans = 0;
        for(int i = 0 ; i < roads.size() ; i++){
            ans += importance[roads[i][0]];
            ans += importance[roads[i][1]];
        }
        return ans;
    }
};