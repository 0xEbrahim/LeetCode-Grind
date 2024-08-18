class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        if(k == 0)return false;
        int l = 0, r = 0;
        int n = v.size();
        unordered_map<int, int>mp;
        while(r < n){
            if(abs(r - l) > k)l++;
            if(mp.count(v[r]) && mp[v[r]] >= r - k) return true;
            mp[v[r]] = r;
            r++;
        }
        return false;
    }
};