class Solution {
public:
    int findComplement(int num) {
        bool ok = false;
        for(int i = 31 ; ~i ; i--){
            if(ok)num = (num ^ (1 << i));
            if((num >> i) & 1 && !ok) ok = true, num = (num ^ (1 << i));
        }
        return num;
    }
};