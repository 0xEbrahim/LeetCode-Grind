class Solution {
public:
    void perm(int ind, vector<int>&nums, vector<int>&comp, vector<vector<int>>&ans, int t){
        if(t < 0) return;
        if(t == 0){
            ans.push_back(comp);
            return;
        }
        if(ind == nums.size()) return;
        for(int i = ind ; i < nums.size() ; i++){
            if(i != ind && nums[i] == nums[i - 1])continue;
            comp.push_back(nums[i]);
            perm(i + 1, nums, comp, ans, t - nums[i]);
            comp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &num, int target) 
    {
     sort(num.begin(), num.end());
     vector<vector<int>>ans;
     vector<int>g ={};
     perm(0, num, g, ans, target);
     return ans;   
    }
};