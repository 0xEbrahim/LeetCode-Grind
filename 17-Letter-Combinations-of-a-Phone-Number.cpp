class Solution {
public:
    void back(int id, string&s, string&comp, vector<string>&ans){
        if(id == s.size()){
            ans.push_back(comp);
            return;
        }
        int cur = ((s[id] - '0') - 2);
        int end = 3;
        end = cur == 5 || cur == 7 ? end + 1 : end;
        int tmp = cur;
        cur *= 3;
        cur = tmp > 5 ? cur = cur + 1 : cur;
        for(int i = cur ; i < cur + end ; i++){
            char c = (i + 'a');
            comp += c;
            back(id + 1, s , comp, ans);
            comp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        string h = "";
        back(0, digits,h, ans );
        return ans;
    }
};