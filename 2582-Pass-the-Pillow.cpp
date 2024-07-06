class Solution {
public:
    int passThePillow(int n, int time) {
        // 1 2 3 4 5 6
        // 0 1 2 3 4 5
        // 10 9 8 7 6 5
        // 10 11 12 13 14 15
        // 20 19 18 17 16 15
        // 20 21 22 23 24 25
        int many = time / (n - 1);
        int ret;
        if(many & 1){
            ret = n - (time % ( n - 1 ));
        }else{
            ret = time % (n - 1) + 1;
        }
        return ret;
    }
};