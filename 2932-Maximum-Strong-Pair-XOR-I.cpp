class Solution {
public:
    int maximumStrongPairXor(vector<int>& v) {
        sort(v.begin(), v.end());
        int l = 0 , r;
        int n = v.size();
        int mx_XOR = 0;
        for(r = 0 ; r < n;){
            if(v[r] - v[l] > v[l]){
                l++;
                continue;
                }
            for(int i = l ; i <= r ; i++) mx_XOR = max(mx_XOR , v[r] ^ v[i]);
            r++;
        }
        return mx_XOR;
    }
};