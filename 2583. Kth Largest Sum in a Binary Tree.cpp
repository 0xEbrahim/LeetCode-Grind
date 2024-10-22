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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>level_sum;
        queue<TreeNode*>q;
        q.push(root);
        while(not q.empty()){
            long long sum = 0;
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                sum += q.front() -> val;
                if(q.front() -> left)
                    q.push(q.front() -> left);
                if(q.front() -> right)
                    q.push(q.front() -> right);
                q.pop();
            }
            level_sum.push_back(sum);
        }
        sort(level_sum.rbegin(), level_sum.rend());
        if(k > level_sum.size()) 
            return -1;
        return level_sum[k - 1];
    }
};
