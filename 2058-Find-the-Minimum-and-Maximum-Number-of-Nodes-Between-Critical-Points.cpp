/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head;
        vector<int>ret = {-1,-1};
        ListNode*cur = prev -> next;
        if(prev -> next == NULL || cur -> next == NULL)
            return ret;
        vector<int>nodes;
        int index = 2;
        ListNode*next = cur -> next;
        int mn = INT_MAX;
        while(next){
            if((cur -> val < prev -> val && cur -> val < next -> val) || (cur -> val > prev -> val && cur -> val > next -> val)){
                if(!nodes.empty()){
                 mn = min(mn, index - nodes.back());   
                }
                nodes.push_back(index);
                
            }
            prev = cur;
            cur = next;
            next = cur -> next;
            index++;
        }
        if(nodes.size() < 2)
            return ret;
        ret.clear();
        ret.push_back(mn);
        ret.push_back(nodes[nodes.size() - 1] - nodes[0]);
        return ret;
    }
};