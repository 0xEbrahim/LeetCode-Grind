class Solution {
public:
vector<int>v;
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
       v.push_back(root -> val);
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return v[k - 1];
    }
    
private:
    int res;
};