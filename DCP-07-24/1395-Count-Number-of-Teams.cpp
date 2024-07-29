const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    int n;
    long long go1(int cur, int prev, int count, vector<vector<vector<long long>>>&dp, vector<int>&rate){
        if(cur >= n){
            if(count == 3)
                return 1;
            return 0;
        }
        if(count == 3)
            return 1;
        if(count > 3)
            return 0;
        long long &ret = dp[cur][prev + 1][count];
        if(~ret)
            return ret;
        ret = 0;
        ret += go1(cur + 1, prev, count, dp, rate);
        if(prev == -1 || rate[cur] > rate[prev])
            ret += go1(cur + 1, cur, count + 1, dp, rate);
        return ret;
    }
    long long go2(int cur, int prev, int count, vector<vector<vector<long long>>>&dp, vector<int>&rate){
        if(cur >= n){
            if(count == 3)
                return 1;
            return 0;
        }
        if(count == 3)
            return 1;
        if(count > 3)
            return 0;
        long long &ret = dp[cur][prev + 1][count];
        if(~ret)
            return ret;
        ret = 0;
        ret += go2(cur + 1, prev, count, dp, rate);
        if(prev == -1 || rate[cur] < rate[prev])
            ret += go2(cur + 1, cur, count + 1, dp, rate);
        return ret;
    }
    int numTeams(vector<int>& rating) {
       n = rating.size();
       vector<vector<vector<long long>>>dp(n + 4, vector<vector<long long>>(n + 4, vector<long long>(5, -1)));
        long long ret = go1(0, -1, 0, dp, rating);
        dp.assign(n + 4, vector<vector<long long>>(n + 4, vector<long long>(5, -1)));
        long long res = go2(0,-1,0,dp,rating);
        return ret + res;
    }
};