class Solution {
public:
// 0 0 0 1 0 1 1 0
// 1 1 1 1 0 1 1 0
// 1 1 1 1 1 0 0 0
// 
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() ;
        bool flipped  = false;
        vector<bool>is_flipped(n, false);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(i >= k)
                flipped ^= is_flipped[i - k];
            if(flipped == nums[i]){
               if(i + k > n)
                return -1;
            is_flipped[i] = true;
            flipped ^= 1;
            ans++;
            }
            
        }
        return ans;
    }
};