const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int longestPalindrome(string s) {
        // for evens freq -> we can put half on the left and half on the right
        // for odd freq -> we can't do the same , we need to take the maximum one and put it on the center
        // the rest of odds we can do (freq - 1) to make them evens, then use it
        int freq[250] = {};
        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i] - 'A' + 1]++;
        }
        int evens = 0, mx_odd = 0, odds = 0;

        for(int i = 0 ; i < 250 ; i++)
            if((freq[i] & 1) && freq[i] > freq[mx_odd])
                mx_odd = i;

        for(int i = 0 ; i < 250 ; i++){
            evens += ((!(freq[i]&1)) ? freq[i] : 0);
            odds += ((freq[i] & 1) && i != mx_odd) ? freq[i] - 1 : 0;
        }
        return evens + freq[mx_odd] + odds;
    }
};