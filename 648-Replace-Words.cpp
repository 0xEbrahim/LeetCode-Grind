const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    string replaceWords(vector<string>& d, string ss) {
        unordered_map<string, bool>mp;
        set<int>st;
        int n = ss.size();
        int m = d.size();
        vector<string>s;
        string cur = \\;
        for(int i = 0 ; i < m ; i++)
            mp[d[i]] = true;
        for(int i = 0 ; i < n ; i++){
            if(ss[i] == ' ')
                {
                    s.push_back(cur);
                    cur = \\;
                    continue;
                }
            cur += ss[i];
        }
        s.push_back(cur);
        n = s.size();
        for(int i = 0 ; i < n ; i++){
                cur = \\;
            for(int j = 0 ; j < min((int)s[i].size(), (int)101) ; j++){
                cur += s[i][j];
                if(mp[cur]){
                    s[i] = cur;
                    break;
                }
            }
        }
        string ans = \\;
        for(int i = 0 ; i < n ; i++){
                ans += s[i];
            if(i != n - 1){
                ans += ' ';
            }
        }
        return ans;
    }
};