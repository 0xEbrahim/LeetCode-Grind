class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int i = 0 ; i < nums.size() ; i++){
                red += nums[i] == 0;
                white += nums[i] == 1;
                blue += nums[i] == 2;
            }
        int pos = 0;
        while(pos < nums.size()){
            while(red--)
                nums[pos++] = 0;
            while(white--)
                nums[pos++] = 1;
            while(blue--)
                nums[pos++] = 2;
        }
    }
};