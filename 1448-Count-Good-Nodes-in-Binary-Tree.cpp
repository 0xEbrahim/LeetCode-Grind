 const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count(TreeNode*root, int mx){
        if(root == NULL) return 0;
        int left = count(root -> left, max(mx, root -> left == NULL ? -100000 : root -> left -> val));
        int right = count(root -> right, max(mx, root -> right == NULL ? -100000 : root -> right -> val));
        if(root -> val == mx)
            return 1 + left + right;
        return left + right;
    }
    int goodNodes(TreeNode* root) {
        return count(root, root -> val);
    }
};