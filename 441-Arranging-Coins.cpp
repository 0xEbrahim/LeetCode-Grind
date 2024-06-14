class Solution {
public:
    bool pred(long long md, int tar){
            long long sum = md * (md + 1) / 2;
            return sum <= tar;
    }
    int arrangeCoins(int n) {
        // n * (n + 1) / 2;
        int ans = 0;
        long long l = 0, r = 1e8 ;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(pred(mid, n)){
                l = mid + 1;
                ans = mid;
            }else
                r = mid - 1;
        }
        return ans;
    }
};