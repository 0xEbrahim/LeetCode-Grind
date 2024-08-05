class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans = "";
        int  n = arr.size();
        unordered_map<string, int>mp;
        for(int i = 0 ; i < n ; i++)
            mp[arr[i]]++;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(mp[arr[i]] == 1)
                cnt++;
            if(cnt == k)
            {
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
};