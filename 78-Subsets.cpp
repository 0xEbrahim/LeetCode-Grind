class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0 ; i < (1 << n) ; i++){
            vector<int>tmp;
            for(int msk = 0 ; msk < n ; msk++){
                if(((i >> msk) & 1))
                    tmp.push_back(nums[msk]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};