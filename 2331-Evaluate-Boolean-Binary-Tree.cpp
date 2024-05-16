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
    void dfs(TreeNode *root){
        if(root == NULL)
            return;
        if(root -> right != NULL && (root -> right -> val == 2 || root -> right -> val == 3))
            dfs(root -> right);
        if(root -> left != NULL && (root -> left -> val == 2 || root -> left -> val == 3))
            dfs(root -> left);
        if(root -> right != NULL && root -> left != NULL){
            if(root -> val == 2)
                root -> val = (root -> right -> val | root -> left -> val);
            else if(root -> val == 3)
                root -> val = (root -> right -> val & root -> left -> val);
        }
    }
    bool evaluateTree(TreeNode* root) {
        dfs(root);
        return root -> val;
    }
};