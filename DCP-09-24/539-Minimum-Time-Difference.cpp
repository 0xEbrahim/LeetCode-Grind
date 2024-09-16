class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
        for(int i = 0 ; i < timePoints.size() ; i++){
            string H = timePoints[i].substr(0,2);
            string M = timePoints[i].substr(3,2);
            int HH = stoll(H);
            int MM = stoll(M);
            v.push_back((HH) * 60 + MM);
            if(HH <= 12){
                v.push_back((HH + 24) * 60 + MM);
            }
        }
        sort(v.begin(), v.end());
        int mn = INT_MAX;
        for(int i = 1 ; i < v.size() ; i++){
            mn = min(v[i] - v[i - 1], mn);
        }
        return mn;
    }
};