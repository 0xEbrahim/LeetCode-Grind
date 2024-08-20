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
    int get(TreeNode*root){
        if(root == NULL) return 0;
        int left =  get(root -> left);
        int right =  get(root -> right);
        return 1 + max(left, right);
    }
    bool dfs(TreeNode*root){
        if(root == NULL) return true;
        bool left = dfs(root -> left);
        cout << left << endl;
        bool right = dfs(root -> right);
        cout << right << endl;
        return abs(get(root -> left) - get(root -> right)) <= 1 && left && right;
    }
    bool can = true;
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        can &= dfs(root);
        return can;
    }
};