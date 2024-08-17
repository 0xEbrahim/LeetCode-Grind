class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {};
        int l = 0 , r = 0 , mx_len = 0;
        int mx_freq = 0;
        while(r < n){
            freq[s[r] - 'A']++;
            mx_freq = max(mx_freq, freq[s[r] - 'A']);
            if(r - l + 1 - mx_freq > k){
                mx_len = max(mx_len, r - l);
                freq[s[l] - 'A']--;
                l++;
                mx_freq = *max_element(freq, freq + 26);
            }
            r++;
        }
        return max(mx_len, r - l);
    }
};