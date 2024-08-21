class Solution {
public:
    vector<vector<int>>st;
    void perm(int id, vector<int>&nums, vector<int>&comp, int target){
        if(target < 0) return;
        if(target == 0){
            st.push_back(comp);
            return;
        }
        for(int i = id ; i < nums.size() ; i++){
            comp.push_back(nums[i]);
            perm(i, nums, comp, target - nums[i]);
            comp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> g ={};
        sort(candidates.begin(), candidates.end());
        perm(0, candidates, g, target);
        return st;
    }   
};