class Solution {
public:
    int deg[100000 + 2] = {};
    int findCenter(vector<vector<int>>& edges) {
        int mx = 0;
        for(int i = 0 ; i < edges.size() ; i++){
            mx = max(mx, max(edges[i][1], edges[i][0]));
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        int ans = 0;
        for(int i = 1 ; i <= mx ; i++){
            if(deg[i] == edges.size()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};