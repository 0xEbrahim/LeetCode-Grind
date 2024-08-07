class Solution {
public:
    static bool dfs(TreeNode* root, int x, auto& path) {
        if (root == NULL)
            return 0;
        if (root->val == x)
            return 1;

        path.push_back('L');
        if (dfs(root->left, x, path)) return 1;
        path.pop_back();

        path.push_back('R');
        if (dfs(root->right, x, path)) return 1;
        path.pop_back();

        return 0;
    }

    static string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathFrom, pathTo;
        dfs(root, startValue, pathFrom);
        dfs(root, destValue, pathTo);

        // Find the point where paths diverge
        int n=pathFrom.size(), m=pathTo.size(), sz = 0;
        int minz = min(n, m);
        while (sz < minz && pathFrom[sz] == pathTo[sz]) 
            sz++;

        return string(n-sz, 'U') + string(pathTo.begin()+sz, pathTo.end());
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
