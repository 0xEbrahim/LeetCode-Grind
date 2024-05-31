class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
\tunordered_map<int, int> freq;
\tfor (auto &num: nums) ++freq[num];
\tvector<int> ans;
\tfor (auto &[x, f]: freq)
\t\tif (f == 1) {
\t\t\tans.push_back(x);
\t\t\tif (ans.size() == 2)
\t\t\t\treturn ans;
\t\t}
\treturn ans;
}
};