const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // get freq of the first word
        // common characters will be taken as they are on the first on and the others
        vector<string>ans;
        int freq[27];
        for(int i = 0 ; i < 26 ; i++)
            freq[i] = 101;
        int n = words.size();
        for(int i = 0 ; i < n ; i++ ){
           int tmp[26] = {};
           for(int j = 0 ; j < words[i].size() ; j++){
            tmp[words[i][j] - 'a']++;
           }
           for(int j = 0 ; j < 26 ; j++)
            freq[j] = min(freq[j], tmp[j]);
        }
        for(int i = 0 ; i < 26 ; i++)
            if(freq[i])
                {
                    string s = "";
                    s += (char)(i + 'a');
                    while(freq[i]--){ans.push_back(s);}
                }
        return ans;
    }
};