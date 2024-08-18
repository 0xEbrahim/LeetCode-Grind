class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v) {
        int n = v.size();
        int ret = 0 ;
        int l = 0;
        int r = 2;
        ret += (v[n - 1] == v[1] && v[0] != v[1]);
        ret += (v[n - 2] == v[0] && v[n - 1] != v[0]);
        while(r < n){
            if(v[r] == v[l] && v[r] != v[r - 1]) ret++;
            r++, l++;
        }
        return ret;
    }
};