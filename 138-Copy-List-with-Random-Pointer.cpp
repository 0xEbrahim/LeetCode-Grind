/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node*root = head;
       Node*trav = root;
       while(trav){
            Node*tmp = trav -> next;
            Node*copyNode = new Node(trav -> val);
            trav -> next = copyNode;
            copyNode -> next = tmp;
            trav = trav -> next -> next;
       }
       trav = root;
       while(trav){
        trav -> next -> random = trav -> random ? trav -> random -> next : NULL;
        trav = trav -> next -> next;
       }
       Node*res = new Node(-1);
       Node*d = res;
       trav = root;
        while(trav && trav -> next){
            d -> next = trav -> next;
            d = d -> next;
            trav -> next = trav -> next -> next;
            trav = trav -> next;
        }
       return res -> next;
    }
};