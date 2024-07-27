const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
const long long INF = 1e18;
const long long  MX = 2e5+20;
long long n , m , st , ed;
long long d[30][30];
vector<vector<pair<int , int>>>adj;

void dijikstra(long long src){
    priority_queue<pair<long long , long long> , vector<pair<long long,long long>>, greater<>>q;
    q.push({0,src});
    for(long long i = 0 ; i <= 29 ; i++){
        d[src][i] = INF;
    }
    d[src][src] = 0;
    while(!q.empty()){
        long long cost = q.top().first;
        long long nd = q.top().second;
        q.pop();
        if(d[src][nd] < cost)
            continue;
        for(auto ch : adj[nd]){
            long long newCost = ch.second + cost;
            if(newCost < d[src][ch.first]){
                d[src][ch.first] = newCost;
                q.push({d[src][ch.first] , ch.first});
            }
        }
    }
}
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    bool can = true;
    m = original.size();
    n = source.size();
    adj.resize(28);
    for(long long i = 0 ; i < m ; i++){
        adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
    }
    for(long long i = 0 ; i < 26 ; i++)
        dijikstra(i);
    long long ans = 0;
    for(long long i = 0 ; i < n ; i++){
        if(d[source[i] - 'a'][target[i] - 'a'] == INF){
            can = false;
            break;
        }else{
            ans += d[source[i] - 'a'][target[i] - 'a'];
        }
    }
    return can ? ans : -1;
}
};