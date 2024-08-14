class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            int i = 0, j = 0;
            for(i ; i < n ; i++){
                while(j < n && nums[j] - nums[i] <= mid) j++;
                j--;
                cnt += (j - i);
            }
            if(cnt >= k)
            r = mid - 1;
            else
            l = mid + 1, ans = mid + 1;
        }
        return ans;
    }
};