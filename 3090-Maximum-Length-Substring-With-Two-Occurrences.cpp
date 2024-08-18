class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0 , r = 0 ;
        vector<int>freq(26, 0);
        int mx_len = 0;
        while(r < n){
            freq[s[r] - 'a']++;
            while(freq[s[r] - 'a'] > 2){
                freq[s[l] - 'a']--;
                l++;
            }
            mx_len = max(r  - l  + 1, mx_len);
            r++;
        }
        return mx_len;
    }
};