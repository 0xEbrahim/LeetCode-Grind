class Solution {
public:
    vector<vector<int>>sub;
    int n;
    vector<int>vs;
    void subs(int i, vector<int>&v){
        sub.push_back(v);
        for(int j = i ; j < n ; j++){
            v.push_back(vs[j]);
            subs(j + 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vs = nums;
        n = vs.size();
        vector<int>g = {};
        subs(0,g);
        return sub;
    }
};