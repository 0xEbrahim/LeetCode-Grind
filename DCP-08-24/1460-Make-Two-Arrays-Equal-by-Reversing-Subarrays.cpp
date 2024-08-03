class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
     int vis[1000 + 1] = {}, viss[1000 + 1] = {};
     for(int i = 0 ; i < target.size() ; i++)
     vis[target[i]]++;
     for(int i = 0 ; i < arr.size() ; i++)
     viss[arr[i]]++;
     for(int i = 0 ; i < target.size() ; i++)
     if(vis[target[i]] != viss[target[i]])
     return false;
    return true;  
    }
};