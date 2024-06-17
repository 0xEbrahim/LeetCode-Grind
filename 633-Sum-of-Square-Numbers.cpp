class Solution {
public:
    bool judgeSquareSum(int c) {
    long long left = 0, right = sqrtl(c);
    while(left <= right){
        long long mul = left * left + right * right;
        if(mul < c)
            left++;
        else if(mul > c)
            right--;
        else
        return true;
    }
    return false;
}

};