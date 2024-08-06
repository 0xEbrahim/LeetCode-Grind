class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        int n = word.size();
        for(int i = 0 ; i < n ; i++){
            freq[word[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] == 0)
                break;
            if(i < 8)
                ans += freq[i];
            else if(i >= 8 && i < 16)
                ans += 2 * freq[i];
            else if(i >= 16 && i < 24)
                ans += 3 * freq[i];
            else
                ans += 4 * freq[i]; 
        }
        return ans;
    }
};