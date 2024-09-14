class Solution {
public:
    int longestSubarray(vector<int>& v) {
      int n = v.size();
      vector<int>pref(n);
      pref[0] = v[0];
      int mx = pref[0];
      for(int i = 1 ; i < n ; i++){
          pref[i] = max(v[i], (pref[i - 1] & v[i]));
          mx = max(pref[i], mx);
      }
      int ret = 0;
      for(int i = 0 ; i < n ; i++){
          int cnt = 0;
          bool inside = false;
          while(i < n && pref[i] == mx){
              cnt++;
              i++;
              inside = true;
          }
          if(inside)
              i--;
          ret = max(ret, cnt);
      }
      return ret;
    }
};