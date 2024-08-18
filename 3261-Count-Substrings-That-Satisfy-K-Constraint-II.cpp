class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
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
        for(auto &q : queries){
            l = q[0];
            r = q[1];
            cur = 0;
            int len = 0;
            for(int i = l ; i <= r ; i++){
                len++;
                if(a[i] <= len){
                    cur = cur + prefix[r + 1] - prefix[i];
                    break;
                }else{
                    cur += len;
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};