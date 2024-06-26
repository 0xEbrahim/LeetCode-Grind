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
    vector<TreeNode*>nodes;
    void traverse(TreeNode*nd){
        if(nd == NULL)
            return;
        traverse(nd -> left);
        nodes.push_back(nd);
        traverse(nd -> right);
    }

    TreeNode* buildTree(int start, int end){
        if(start >= end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = nodes[mid];
        root -> left = buildTree(start, mid);
        root -> right = buildTree(mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        int n = nodes.size();
        return buildTree(0, n );
    }
};