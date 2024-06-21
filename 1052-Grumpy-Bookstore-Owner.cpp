const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        vector<int>leave(n);
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(grumpy[i])
                leave[i] = customers[i];
            else
                sum += customers[i];
        }
        for(int i = 1 ; i < n ; i++){
                
                leave[i] += leave[i - 1];
        }
        int ans = 0;
        for(int i = minutes - 1 ; i < n ; i++){
            ans = max(ans, sum + (leave[i] - (i - minutes + 1 == 0 ? 0 : leave[i - minutes])));
        }
        return ans;
    }
};