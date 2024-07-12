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
    bool find[100000 + 5] = {}; 
    bool findValue(int val,TreeNode*root){
        if(root == NULL)
            return false;
        find[root -> val] = true;
        if(root -> val == val)
            return true;
        bool right = false, left = false;
        if(val > root -> val)
            right = findValue(val, root -> right);
        else
            left = findValue(val, root -> left);
        return right || left ;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;
        for(int i = low ; i <= high ; i++){
            TreeNode*tmp = root;
            if(find[i] || findValue(i, root)){
                root = tmp;
                ret += i;
            }
        }
        return ret;
    }
};