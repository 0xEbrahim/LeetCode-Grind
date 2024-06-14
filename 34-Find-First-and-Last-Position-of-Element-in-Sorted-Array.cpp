class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans1 = -1, ans2 = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target){
                r = mid - 1;
                if(nums[mid] == target)
                ans1 = mid;
            }else{
                l = mid + 1;
            }
        }
        l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target){
                l = mid + 1;
                if(nums[mid] == target)
                ans2 = mid;
            }else{
                r = mid - 1;
            }
        }
        vector<int>ans  = {ans1, ans2};
        
        return ans;
    }
};