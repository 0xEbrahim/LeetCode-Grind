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
    void reorderList(ListNode* head) {
        ListNode*fast = head;
        ListNode*slow = head;
        ListNode*root = head;
        ListNode*dummy = root;
        while(fast!=NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode*prev = NULL;
        ListNode*nxt = slow;
        ListNode*cur = slow;
        while(cur){
            nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
        }
        while(dummy != slow && prev != NULL){
        ListNode*temp = dummy -> next;
        dummy -> next = new ListNode(prev -> val);
        dummy = dummy -> next;
        if(prev == slow)break;
        dummy -> next = temp;
        dummy = dummy -> next;
        if(dummy == slow)break;
        prev = prev -> next;
    }
    }
};