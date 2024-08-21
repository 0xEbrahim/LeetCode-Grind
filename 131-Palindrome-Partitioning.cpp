class Solution {
public:
    bool isPal(vector<string>&v, string&ss){
        bool ret = true;
        int sum = 0;
        for(auto &s : v){
            sum += s.size();
        for(int i = 0 ; i < s.size() / 2 ; i++) ret &= s[i] == s[s.size() - i - 1];
        }
        return ret && sum == ss.size();
    }
    void back(int idx, string&s, vector<vector<string>>&ans, vector<string>&comp, string tmp){
        if(idx == s.size()){
            if(isPal(comp, s)){
                ans.push_back(comp);
                return;
            }
            return;
        }
        tmp += s[idx];
        back(idx + 1, s , ans, comp, tmp);
        comp.push_back(tmp);
        back(idx + 1, s , ans, comp, "");
        comp.pop_back();
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>g = {};
        back(0, s, ans, g, "");
        return ans;
    }
};