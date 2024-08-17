const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
bool check(int freqT[]){
    bool ret = true;
    for(int i = 0 ; i < 300 ; i++)
        ret &= freqT[i] <= 0;
    return ret;
}
string minWindow(std::string s, std::string t) {
    int n = s.size();
    int m = t.size();
    int freqT[300] = {};
    bool exist[300] ={};
    vector<pair<int, int>>ranges;
    for(int i = 0 ; i < m ; i++){
        freqT[t[i] - 'A']++;
        exist[t[i] - 'A'] = true;
    }
    int l = 0 , r = 0;
    int l_ret = 0, r_ret = 0, mn_ret = INT_MAX;
    while(r < n){
        if(exist[s[r] - 'A'])
            freqT[s[r] - 'A']--;
        while(check(freqT)){
            if(r - l + 1 < mn_ret){
                l_ret = l, r_ret = r + 1, mn_ret = r - l + 1;
                }
            if(exist[s[l] - 'A'])
                freqT[s[l] - 'A']++;
            l++;
        }
        r++;
    }
    if(check(freqT))
        if(r - l + 1 < mn_ret)
            l_ret = l, r_ret = r + 1, mn_ret = r - l + 1;
    string ret ="";
    cout << l_ret << " " << r_ret;
    for(int i = l_ret ; i < r_ret ; i++)
        ret += s[i];
    return ret;
}
};