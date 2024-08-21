class Solution {
public:
    vector<vector<int>>res;
    void perm(vector<int>&nums, vector<int>&sub, vector<bool>&vis){
        if(sub.size() == nums.size()) {
            res.push_back(sub); return;
            }
        for(int i = 0 ; i < nums.size() ; i++){
            if(vis[i]) continue;
            sub.push_back(nums[i]);
            vis[i] = true;
            perm(nums, sub, vis);
            vis[i] = false;
            sub.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>g = {};
        vector<bool> vis(nums.size() + 1, false);
        perm(nums, g, vis);
        return res;
    }
};