const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    vector<int>coin ,day;
int dp[370][370][35];
int n;
int go(int index , int prev, int type){
    if(index == n)
        return 0;
    int &ret = dp[index][prev][type];
    if(~ret)
        return ret;
    ret = 365000 + 10;
    if(index == 0 || day[index] - prev >= type){
        for(int i = 0 ; i < 3 ; i++){
            ret = min(ret, go(index + 1, day[index], (i == 0) ? 1 : (i == 1) ? 7 : 30) + coin[i]);
        }
    }else{
        ret = min(ret, go(index + 1, prev, type));
    }
    return ret;
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    n = days.size();
    memset(dp, -1, sizeof dp);
    for(int i = 0 ; i < n ; i++)
        day.push_back(days[i]);
    for(int i = 0 ; i < 3 ; i++)
        coin.push_back(costs[i]);
    return go(0,366, 0);
}
};