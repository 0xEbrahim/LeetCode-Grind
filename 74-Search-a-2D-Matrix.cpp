class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n = v.size();
        int m = v[0].size();
        int l = 0 , r = n * m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[mid / m][mid % m] > target) r = mid - 1;
            else if(v[mid / m][mid % m] < target) l = mid + 1;
            else return true;
        }
        return false;
    }
};