const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>>v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = {difficulty[i], profit[i]};
        }
        sort(v.begin(), v.end());
        for(int i = 1 ; i < n ; i++){
            v[i].second = max(v[i].second, v[i - 1].second);
        }
        int m = worker.size(); 
        int total = 0;
        for(int i = 0 ; i < m ; i++){
            int cur = worker[i];
            int l = 0 , r = n - 1 ;
            int ans = -1;
            while(l <= r){
                int mid = l + (r - l)/2;
                int diff = v[mid].first;
                int val = v[mid].second;
                if(cur >= diff){
                    l = mid + 1;
                    ans = val;
                }else{
                    r = mid - 1;
                }
            }
            if(ans != -1)
                total += ans;
        }
        return total;
    }
};