class Solution {
public:
    bool isPal(string s){
        bool ret = true;
        
        for(int i = 0 ; i < s.size() / 2 ; i++) ret &= s[i] == s[s.size() - i - 1];
        
        return ret;
    }
    void back(int idx, string&s, vector<vector<string>>&ans, vector<string>&comp){
        if(idx == s.size()){
                ans.push_back(comp);
                return;
        }

       for(int i = idx ; i < s.size() ; i++){
        if(isPal(s.substr(idx, (i - idx) + 1))){
         comp.push_back(s.substr(idx, (i - idx) + 1));
         back(i + 1, s , ans, comp);
         comp.pop_back();}
    }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>g = {};
        back(0, s, ans, g);
        return ans;
    }
};