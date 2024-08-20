class Solution {
public:
    int n;
    bool check(long long mid, int h , vector<int>&v){
        long long required = 0;
        for(int i = 0 ; i < n ; i++){
            required += ((v[i] / mid) + (v[i] % mid > 0));
        }
        return required <= h;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        n = v.size();
        long long l = 1 , r = 1e9;
        long long ret = 0;
        while(l <= r){
        long long mid = l + (r - l) / 2;
        if(check(mid, h, v)){
            r = mid - 1;
            ret = mid;
        }else{
            l = mid + 1;
        }
    }
        return ret;
    }
};