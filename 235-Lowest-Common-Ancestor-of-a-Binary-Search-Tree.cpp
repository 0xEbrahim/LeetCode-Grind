/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, int>lvl;
    unordered_map<TreeNode*, map<int, TreeNode*>>anc;
    void build(TreeNode*node, TreeNode*par){
        if(node == NULL) return;
        lvl[node] = lvl[par] + 1;
        anc[node][0] = par;
        for(int i = 1 ; i < 24 ; i++){
            TreeNode*p = anc[node][i - 1];
            anc[node][i] = anc[p][i - 1];
        }
        build(node -> left, node);
        build(node -> right, node);
    }
    TreeNode*getKth(TreeNode*node, int k){
        for(int i = 23 ; ~i ; i--){
            if((k >> i) & 1)
                node = anc[node][i];
        }
        return node;
    }

    TreeNode*getLCA(TreeNode*u, TreeNode*v){
        if(lvl[u] < lvl[v]) swap(u, v);
        u = getKth(u, lvl[u] - lvl[v]);
        if(u == v) return u;
        for(int i = 23 ; ~i ; i--){
            if(anc[u][i] != anc[v][i]){
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        build(root, root);
        return getLCA(p, q);
    }
};