class Solution {
public:
    
    int maxProduct(vector<int>& v) {
        if(v.empty()) return 0;
        long double maxi = 1;
        long double  mini = 1;
        long double  ans = LLONG_MIN;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i] < 0) swap(maxi, mini);
            long double m = v[i];
            maxi = max(m, maxi * m);
            mini = min(m, mini * m);
            ans = max(ans, maxi);
        }
        return (int)ans;
    }
};