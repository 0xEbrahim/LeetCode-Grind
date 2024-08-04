class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>sums;
        for(int i = 0 ; i < n ; i++){
            long long sum = 0;
            for(int j = i ; j < n ; j++){
                sum+=nums[j];
                sums.push_back(sum % mod);
            }
        }
        sort(sums.begin(), sums.end());
        for(int i = 1 ; i < sums.size() ; i++){
            sums[i] += sums[i - 1];
            sums[i] %= mod;
            }
        return left - 1 == 0 ? sums[right - 1] :sums[right - 1] - sums[left - 2];
    }
};