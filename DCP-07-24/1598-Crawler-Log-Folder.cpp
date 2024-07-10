class Solution {
public:
    int minOperations(vector<string>& logs) {
        int counter = 0 ;
        int n = logs.size();
        for(int i = 0 ; i < n ; i++){
            counter -= (counter > 0 ? (logs[i] == "../") : 0);
            counter += (logs[i][0] != '.');
        }
        return counter;
    }
};