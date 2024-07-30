class Solution {
public:
    
    int minimumDeletions(string s) {
      int n = s.size();
      vector<int>A(n, 0);
      for(int i = n - 2 ; ~i ; i--){
        A[i] = s[i + 1] == 'a';
        }
      for(int i = n - 2 ; ~i ; i--)
        A[i] += A[i + 1];
    int ans = INT_MAX;
    int c = 0;
    for(int i = 0 ; i < n ; i++){
        ans = min(ans, c + A[i]);
         if(s[i] == 'b')
            c++;
        }
    return ans;
    }
};