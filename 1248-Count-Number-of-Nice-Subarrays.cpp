class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        int n = v.size();
        vector<int>count(n + 1 , 0);
        count[0] = 1;
        int ans = 0;
        int counter = 0;
        for(int i = 0 ; i < n ; i++){
            counter += (v[i] & 1);
            if(counter - k >= 0){
                ans += count[counter - k];
            }
            count[counter]++;
        }
        return ans;
    }
};