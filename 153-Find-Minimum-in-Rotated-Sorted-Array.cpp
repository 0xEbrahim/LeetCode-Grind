class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n - 1 ;
        int ans = -1;
        while(l < r){
             if (nums[l]<nums[r])
                return nums[l];
            int mid =  l + (r - l ) / 2;
            if(nums[mid] >= nums[l]) l = mid + 1, ans = mid;
            else r = mid;
        }
        return nums[l];
    }
};