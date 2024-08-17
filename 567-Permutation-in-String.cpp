class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int n = s1.size();
        int m = s2.size();
        int freq1[26] = {};
        int freq2[29] = {};
        for(int i = 0 ; i < n ; i++)
            freq1[s1[i] - 'a']++, freq2[s2[i] - 'a']++;
        if(matches(freq1, freq2)) return true;
        for(int i = n;i<s2.length();i++){
            freq2[s2[i]- 'a']++;
            freq2[s2[i-n] - 'a']--;
            if(matches(freq1,freq2)) return true;
        }
        return matches(freq1, freq2);
    }
    bool matches(int s1count[], int s2count[]) {
    for (int i = 0; i < 26; i++) {
        if (s1count[i] != s2count[i])
            return false;
    }
    return true;
}
};