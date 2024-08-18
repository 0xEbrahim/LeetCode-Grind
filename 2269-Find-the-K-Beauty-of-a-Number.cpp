class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numb = to_string(num);
        int l = 0 , r = k - 1;
        string div = "";
        int ret = 0;
        for(int i = 0 ; i <= numb.size() - k ; i++){
            div = numb.substr(i, k);
            int converted = stoi(div);
            ret += (converted != 0 && num % converted == 0);
        }
        return ret;
    }
};