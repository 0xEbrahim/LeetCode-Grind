class Solution {
public:
   vector<bool>vis;
vector<vector<int>>adj;
vector<int>anc;
vector<vector<int>>ans;
void dfs(int node){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            anc.push_back(it);
            dfs(it);
        }
    }
}
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    adj.assign(n + 10, vector<int>());
    ans.assign(n, vector<int>());
    vis.assign(n + 1, false);
    for(int i = 0 ; i < edges.size() ; i++){
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0 ; i < n ; i++){
        anc = {};
        dfs(i);
        vis.assign(n + 1, false);
        ans[i] = anc;
    }
    for(int i = 0 ; i < ans.size() ; i++)
        sort(ans[i].begin(), ans[i].end());
    return ans;
}
};