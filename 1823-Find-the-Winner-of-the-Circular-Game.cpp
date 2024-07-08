class Solution {
public:
    int findTheWinner(int n, int k) {
    vector<bool>vis(n + 1, false);
    int cnt = 0, count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]){
            if(i == n){
            i = 0;
        }
            continue;
            }
        cnt++;
         if(count == n - 1)
            break;
        if(cnt == k){
            vis[i] = true;
            cnt = 0;
            count++;
        }

        if(i == n){
            i = 0;
        }
    }
    int ret = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            ret = i;
            break;
        }
    }
    return ret;
}
// 1 2 3 4 5
// 1 2 4 5
// 2 4 5
// 2 4
// 4
};