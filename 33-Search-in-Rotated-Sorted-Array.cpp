class Solution {
public:
    
int search(vector<int>& v, int target) {
    int n = v.size();
    int l = 0 , r = n - 1;
    int ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(v[mid] == target) return mid;
        if(v[l] <= v[mid]){
            if(v[l] <= target && target < v[mid]) r = mid - 1;
            else l = mid + 1;
        }else{
            if(v[mid] < target && target <= v[r]){
                l = mid + 1;
            }else
                r = mid - 1;
        }
    }
    return -1;
}
};