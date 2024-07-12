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
    ListNode* swapPairs(ListNode* head) {
        vector<int>odd,even;
        int cnt = 0;
        while(head){
            cnt++;
            if(cnt % 2 == 1){
                odd.push_back(head -> val);
            }else{
                even.push_back(head -> val);
            }
            head = head -> next;
        }
        ListNode*ret = new ListNode(0);
        int i = 0 , j = 0;
        cnt = 0;
        ListNode*calc = ret;
        while(i < odd.size() && j < even.size()){
            cnt++;
            if(cnt % 2 == 1){
                calc -> next = new ListNode(even[j++]);
            }else{
                calc -> next = new ListNode(odd[i++]);
            }
            calc = calc -> next;
        }
        while(i < odd.size()) { calc -> next = new ListNode(odd[i++]); calc = calc -> next;}
        while(j < even.size()){ calc -> next = new ListNode(even[j++]); calc = calc -> next;}
        return ret -> next;
    }
};