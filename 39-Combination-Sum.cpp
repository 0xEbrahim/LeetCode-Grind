class Solution {
public:
    set<vector<int>>st;
    void perm(vector<int>&nums, vector<int>&comp, int target){
        if(target < 0) return;
        if(target == 0){
            vector<int>vv = comp;
            sort(vv.begin(), vv.end());
            st.insert(vv);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            comp.push_back(nums[i]);
            perm(nums, comp, target - nums[i]);
            comp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> g ={};
        perm(candidates, g, target);
        vector<vector<int>>v(st.begin(), st.end());
        return v;
    }   
};