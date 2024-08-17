class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int prev_mx = 0;
        for(int i = prices.size() - 1 ; ~i ; i--){
            ret = max(ret, prev_mx - prices[i]);
            prev_mx = max(prev_mx, prices[i]);
        }
        return ret;
    }
};