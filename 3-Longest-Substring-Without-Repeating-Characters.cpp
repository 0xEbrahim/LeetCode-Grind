class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0, r = 0, max_len = 0;
       set<char>st;
       int n = s.size();
       while(r < n){
        while(st.count(s[r]) && l < r){
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);
        max_len = max(max_len, r - l + 1);
        r++;
       }
       return max_len;
    }
};