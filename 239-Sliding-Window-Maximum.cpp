 const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ret;
        int n = nums.size();
        int l = 0 , r = k - 1;
        multiset<int>st;
        for(int i = 0 ; i <= r ; i++) st.insert(nums[i]);
        ret.push_back(*st.rbegin());
        while(r < n - 1){
            auto it = st.lower_bound(nums[l]);
            st.erase(it);
            l++;
            r++;
            st.insert(nums[r]);
            ret.push_back(*st.rbegin());
        }
        return ret;
    }
};