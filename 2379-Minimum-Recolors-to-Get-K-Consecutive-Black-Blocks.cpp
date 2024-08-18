class Solution {
public:
    int minimumRecolors(string v, int k) {
        int n = v.size();
        int l = 0 ;
        int r = k - 1;
        int not_B = 0;
        int ret = INT_MAX;
        for(int i = 0 ; i <= r ; i++) not_B += v[i] != 'B';
        ret = not_B;
        while(r < n - 1){
            not_B -= v[l] != 'B';
            l++, r++;
            not_B += v[r] != 'B';
            ret = min(ret, not_B);
        }
        return ret;
    }
};