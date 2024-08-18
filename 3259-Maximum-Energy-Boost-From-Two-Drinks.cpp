class Solution {
public:
    int n;
    vector<int>A, B;
    vector<vector<long long>>dp;
    long long go(int idx, int cur){
        if(idx >= n)
            return 0;
        long long &ret = dp[idx][cur];
        if(~ret) return ret;
        ret = 0;
        if(cur != 1)
            ret = max(ret, max(go(idx + 1, 2) + B[idx], go(idx + 2, 1) + B[idx]));
        if(cur != 2)
            ret = max(ret, max(go(idx + 1, 1) + A[idx], go(idx + 2, 2) + A[idx]));
        return ret;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        A = energyDrinkA;
        B = energyDrinkB;
        n = energyDrinkA.size();
        dp.resize(n, vector<long long>(3, -1));
        // 1 -> A
        // 2 -> B
        return go(0,0);
    }
};