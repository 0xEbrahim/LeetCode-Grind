class Solution {
public:
    string countOfAtoms(string f) {
        stack<map<string,int>> st;
        map<string, int> cur;
        for (int i = 0; i < f.size();) {
            if (f[i] == '(') {
                st.push(move(cur));
                cur = map<string,int>();
                ++i;
            }
            else if (f[i] == ')') {
                int j = i+1;
                int num = 0;
                while (j < f.size() && isdigit(f[j])) num = num*10 + (f[j++] - '0');
                num = max(num,1);
                for (auto p:cur) st.top()[p.first] += p.second * num;
                cur = move(st.top());
                st.pop();
                i = j;
            }
            else {
                int j = i + 1;
                while (j < f.size() && f[j] >= 'a' && f[j] <= 'z') ++j;
                auto name = f.substr(i,j-i);
                int num = 0;
                while (j < f.size() && isdigit(f[j])) num = num*10 + (f[j++] - '0');
                num = max(num,1);
                cur[name] += num;
                i = j;
            }
        }
        string ans;
        for (auto p:cur) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }
        
        return ans;
    }
};