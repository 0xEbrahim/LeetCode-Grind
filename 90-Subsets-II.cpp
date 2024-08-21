class Solution {
public:
set<vector<int>>sub, k;
    int n ;
    void subs(int i , vector<int>&nums, vector<int>&v){
        vector<int> l = v;
        sort(l.begin(), l.end());
        if(not k.count(l))
            k.insert(l), sub.insert(v);
        for(int j = i ; j < n ; j++){
            v.push_back(nums[j]);
            subs(j + 1, nums, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int>g = {};
        subs(0,nums,g);
        vector<vector<int>>ret(sub.begin(), sub.end());
        return ret;
    }
};