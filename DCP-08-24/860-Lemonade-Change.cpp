const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
    int n = v.size();
    vector<int>freq(21,0);
    bool ret = true;
    for(int i = 0 ; i < n ; i++){
        if(v[i] == 5){
            freq[5]++;
        }else if(v[i] == 10){
            ret&=(freq[5] > 0);
            freq[10]++, freq[5]--;
        }else if(v[i] == 20){
            if(freq[5] > 0 && freq[10] > 0)
                freq[20]++, freq[5]--, freq[10]--;
            else if(freq[5] > 2)
                freq[20]++, freq[5]-=3;
            else
                ret = false;
        }
    }
    return ret;
}
};