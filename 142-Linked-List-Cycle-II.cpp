/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
                break;
        }
        fast = head;
        while(fast && slow){
            if(fast == slow)break;
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};