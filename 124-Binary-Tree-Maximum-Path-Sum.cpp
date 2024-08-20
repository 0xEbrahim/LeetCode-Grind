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
    int sum = INT_MIN;
    int ans = 0;
    int get_sum(TreeNode*node){
        if(node == NULL) 
            return 0;
        int l =max(0,  get_sum(node -> left));
        int r = max(0, get_sum(node -> right));
        int price = node -> val + l + r;
        sum = max(sum , price);
        return node -> val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        get_sum(root);
        return sum;
    }
};