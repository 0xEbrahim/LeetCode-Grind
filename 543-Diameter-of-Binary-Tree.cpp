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
    int ret = 0;
    int get(TreeNode*node){
        if(node == NULL) return 0;
        return 1 + max(get(node -> left), get(node -> right));
    }
    int diameterOfBinaryTree(TreeNode *node){
        if(node == NULL) return 0;
        int left =  get(node -> left);
        int right =  get(node -> right);
        ret = max(ret, left + right);
        diameterOfBinaryTree(node -> left);
        diameterOfBinaryTree(node -> right);
        return ret;
    }
};