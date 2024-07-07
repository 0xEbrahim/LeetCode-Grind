class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ret = n;
        while(n >= m){
            ret += (n / m);
            n = (n / m) + (n % m);
        }
        return ret;
    }
};