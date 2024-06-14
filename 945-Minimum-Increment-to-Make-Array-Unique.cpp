class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int>freq;
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0 ; i < n ; i++)
            freq[nums[i]]++,mn = min(mn, nums[i]), mx = max(mx, nums[i]);
        set<int>st;
        for(int i = mn + 1 ; i <= mx + n + 2 ; i++){
            if(!freq[i])
                st.insert(i);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(freq[nums[i]] > 1){
                freq[nums[i]]--;
            auto it = st.upper_bound(nums[i]);
            ans += (*it - nums[i]);
            st.erase(it);
            }
        }
        return ans;
    }
};