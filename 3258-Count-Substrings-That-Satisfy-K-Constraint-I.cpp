class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        vector<long long>ret;
        int n = s.size();
        vector<long long>prefix(n + 1);
        vector<long long>a(n);
        int l = 0 , r;
        long long ones = 0 , zeros = 0;
        long long cur = 0;
        for(r = 0; r < n ; r++){
            s[r] == '0' ? zeros++ : ones++;
            while(zeros > k && ones > k){
                s[l] == '1' ? ones-- : zeros--;
                l++;
            }
            cur = r - l + 1;
            a[r] = cur;
        }
        for(int i = 0 ; i < n ; i++) prefix[i + 1] = prefix[i] + a[i];
        return prefix[n];
    }
};