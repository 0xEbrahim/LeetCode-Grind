class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double cur_time = c[0][0] , waiting_time = 0 ;
        int n = c.size();
        for(int i = 0 ; i < n ; i++){
            cur_time = max(cur_time, (double)c[i][0]);
            waiting_time += max(0.0000, (cur_time - c[i][0]));
            waiting_time += c[i][1];
            cur_time += c[i][1];
        }
        double ret_value = waiting_time / (1.0 * n);
        return ret_value;
    }
};