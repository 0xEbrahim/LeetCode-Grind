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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode*us = head;
        int counter = 0;
        ListNode*Front = head;
        ListNode*back = head;
        ListNode*root = head;
        int sz = 0;
        while(root){
            sz++;
            root = root -> next;
        }
        sz = sz - k + 1;
        while(head){
            counter++;
            if(counter == k){
                Front = head;
            }
            if(counter == sz){
                back = head;
            }
            head = head -> next;
        }
        int x = back -> val;
        back -> val = Front -> val;
        Front -> val = x;
        return us;
    }
};