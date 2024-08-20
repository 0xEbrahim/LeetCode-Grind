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
    struct P{
        TreeNode*node;
        int lvl;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>lvls(2001);
        queue<P>q;
        q.push({root, 0});
        while(not q.empty()){
            TreeNode*node = q.front().node;
            int level = q.front().lvl;
            q.pop();
            lvls[level].push_back(node -> val);
            if(node -> left) q.push({node -> left, level + 1});
            if(node -> right) q.push({node -> right, level + 1});
        }
        vector<vector<int>>ret;
        for(int i = 0 ; i < lvls.size() ; i++) if(not lvls[i].empty()) ret.push_back(lvls[i]);
        return ret;
    }
};