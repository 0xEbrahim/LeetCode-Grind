const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int countSeniors(vector<string>& d) {
        int n = d.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += ((d[i][11] - '0') * 10 + (d[i][12] - '0')) > 60;
        }
        return ans;
    }
};