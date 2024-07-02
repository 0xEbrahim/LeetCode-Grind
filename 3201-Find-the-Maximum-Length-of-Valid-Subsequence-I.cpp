class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nums[i] = (nums[i] % 2);
        }
        int ones = 0 , zeros = 0 ;
        int one_zero = 0 , zero_one = 0;
        int one_zero_cur = 1, zero_one_cur = 0;
        for(int i = 0 ; i < n ; i++){
            ones+=(nums[i]==1);
            zeros+=(nums[i]==0);
            if(nums[i] == one_zero_cur){
                one_zero_cur = !one_zero_cur;
                one_zero++;
            }
            if(nums[i] == zero_one_cur){
                zero_one_cur = !zero_one_cur;
                zero_one++;
            }
        }
        int ret = max({ones, zeros, zero_one, one_zero});
        return ret;
    }
};