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
    bool can = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if((q == NULL && p != NULL) || (p == NULL && q != NULL)) return false;
         if(q == NULL && p == NULL) return true;
        bool left =  isSameTree(p -> left, q -> left);
        bool right =  isSameTree(p -> right, q -> right);
         return p -> val == q -> val && left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root -> val == subRoot -> val){
            can |= isSameTree(root, subRoot);
        }
        bool left = isSubtree(root -> left, subRoot);
        bool right = isSubtree(root -> right, subRoot);
        return can || left || right;
    }
};