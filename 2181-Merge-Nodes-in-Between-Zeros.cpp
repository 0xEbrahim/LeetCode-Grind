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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode *ret = new ListNode();
        ListNode* use = ret;
        bool start_with_zero = 0;
        start_with_zero = (head -> val == 0);
        while(head){
            sum += head -> val;
            if(head -> val == 0){
                use -> next  = new ListNode(sum);
                use = use -> next;
                sum = 0;
            }
            head = head -> next;
        }
        ret = ret -> next;
        if(start_with_zero)
            ret = ret -> next;
        return ret;
    }
};