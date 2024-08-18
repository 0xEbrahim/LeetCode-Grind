const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int>ret(n, 0);
    if(k == 0) return ret;
    vector<int>pref(n, 0);
    pref = code;
    for(int i = 1 ; i < n ; i++)
        pref[i] += pref[i - 1];
    for(int i = 0 ; i < n ; i++) {
        if(k > 0){
            ret[i] = ((i + k) / n ? pref[n - 1] - pref[i] + pref[(i + k) % n] : pref[i + k] - pref[i]);
        }else{
            ret[i] = (i + k < 0 ? (i - 1 >= 0 ? pref[i - 1] + pref[n - 1] - pref[n  - (abs(k) - (i - 1))] : pref[n - 1] - pref[n - abs(k) - 1]) : pref[i - 1] - (i + k - 1 < 0 ? 0 : pref[i + k - 1]));
        }
    }
    return ret;
}
};