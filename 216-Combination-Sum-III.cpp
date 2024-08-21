class Solution {
public:
    vector<int>nums = {1,2,3,4,5,6,7,8,9};
    void perm(int idx, vector<int>&comp, vector<vector<int>>&ans, int n, int t){
        if(t == 0 && n == 0){
            ans.push_back(comp);
        }
        if(idx == 10 || n == 0 || t == 0) return;
        for(int i = idx ; i <= 9 ; i++){
            comp.push_back(i);
            perm(i + 1, comp, ans, n - 1, t - i);
            comp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>g = {};
        perm(1, g, ans, k, n);
        return ans;
    }
};