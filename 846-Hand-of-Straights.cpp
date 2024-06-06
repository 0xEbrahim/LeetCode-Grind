class Solution {
public:
    
    bool isNStraightHand(vector<int>& v, int k) {
       map<int, int>mp;
       for(auto i : v)  mp[i]++;
        for(auto it : mp)
           if(mp[it.first] > 0)
            for(int i = k - 1 ; i >= 0 ; i--)
                if((mp[it.first + i] -= mp[it.first]) < 0)
                    return false;
        return true;
        }
};