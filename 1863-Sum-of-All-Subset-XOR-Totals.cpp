class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // complete search 
        int n = nums.size();
            int sum = 0;
        for(int i = 0 ; i < (1 << n) ; i++){
            int subXOR = 0;
            for(int mask = 0 ; mask < n ; mask++){
                if(((i >> mask) & 1))
                    subXOR ^= nums[mask];
            }
            sum += subXOR;
        }
        return sum;
    }
};