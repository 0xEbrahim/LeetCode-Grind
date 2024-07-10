class Solution {
public:
int n;
vector<vector<long long>>station;
long long dp[502][502];
long long go(int index, int can_be_used, int&cur_fuel){
    if(can_be_used == 0){
        dp[index][can_be_used] = cur_fuel;
        return dp[index][can_be_used];
    }
    if(can_be_used > index)
        return dp[index][can_be_used] = INT_MIN;
    long long &ret = dp[index][can_be_used];
    if(~ret)
        return ret;
    long long op1 = go(index - 1, can_be_used, cur_fuel);
    long long op2 = go(index - 1, can_be_used - 1 , cur_fuel);
    dp[index][can_be_used] = max(op1, op2<station[index-1][0]?INT_MIN:op2+station[index-1][1]);
    return dp[index][can_be_used];
}
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    vector<int>tar = {target, 0};
    stations.push_back(tar);
    n = stations.size();
    station.resize(n);
    for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < stations[i].size() ;j++){
                station[i].push_back(stations[i][j]);
            }
        }
    memset(dp , -1 , sizeof dp);
    for(int i=0;i<=n;i++)
            go(n, i, startFuel);
    int result = -1;
        for(int i=0;i<=n;i++) {
            if(dp[n][i]>=target){
                result = i;
                break;
            } 
        }
        return result;
    }
};