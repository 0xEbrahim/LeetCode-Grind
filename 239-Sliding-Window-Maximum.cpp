 const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ret;
        int n = nums.size();
        int l = 0 , r = 0;
        deque<int>q;
        for(int i = 0 ; i < n ; i++){
            if(not q.empty() && q.front() == i - k) q.pop_front();
            while(not q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k - 1) ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};