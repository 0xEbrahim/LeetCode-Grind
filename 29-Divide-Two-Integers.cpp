class Solution {
public:
    int divide(int d, int ddr) {
        long long dd = d, dr = ddr;
        bool same_sign = (dd > 0 && dr > 0) || (dd < 0 && dr < 0);
        if(dr == 1 || dr == -1){
            long long ret = abs((long long)dd) * (!same_sign ? -1 : 1);
            if(ret >= 2147483647)
                return 2147483647;
            return ret;
        }
        dr = abs(dr) , dd = abs(dd);
        int count = 0;
        while(dd >= dr){
            count++;
            dd -= dr;
        }
        return count * (same_sign == false ? -1 : 1);
    }
};