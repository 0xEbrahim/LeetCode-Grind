class Solution {
public:
    int countGoodSubstrings(string s) {
    if(s.size() < 3)
        return 0;
    int n = s.size();
    int l = 0 , r = 2;
    int ret = 0;
    set<char>st;
    vector<int>vis(26, 0);
    for(int i = 0 ; i <= r ; i++)
        st.insert(s[i]), vis[s[i] - 'a']++;
    ret += st.size() == 3;
    while(r < n - 1){
        vis[s[l] - 'a']--;
        if(vis[s[l] - 'a'] == 0)
            st.erase(s[l]);
        l++;
        r++;
        st.insert(s[r]);
        vis[s[r] - 'a']++;
        ret += st.size() == 3;
    }
    return ret;
}
};