class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int>mp;
        for(auto it : nums)
            mp[it]++;
        for(auto &[a , b] : mp){
            if(b > 0){
                for(int i = k - 1 ; i >= 0 ; i--)
                    if((mp[a + i] -= mp[a]) < 0)
                        return 0;
            }
        }
        return true;
    }
};