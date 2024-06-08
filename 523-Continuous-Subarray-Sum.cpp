const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int>mp;
    int sum = 0;
    bool found = false;
    int last = 0;
    for(int i = 0 ; i < n ; i++){
        sum += nums[i];
        int mod = sum % k ;
        if(mp.count(mod)){
            if(i - mp[mod] >= 1){
                found = true;
                break;
            }
        }
        if(mod == 0){
            if(i >= 1)
            {
                found = true;
                break;
            }
        }
        if(!mp[(nums[i] + last) % k])
            mp[(nums[i] + last) % k] = i + 1;
        else
            mp[(nums[i] + last) % k] = min(mp[(nums[i] + last) % k], i + 1);
        last += nums[i];
    }
    return found;
}
};