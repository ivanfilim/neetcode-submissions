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
        Node dummy(0);
        Node *curr = head, *currCopy = &dummy;
        map<Node*, Node*> copies;
        while (curr) {
            currCopy->next = new Node(curr->val);
            copies[curr] = currCopy->next;
            curr = curr->next;
            currCopy = currCopy->next;
        }
        curr = head;
        currCopy = dummy.next;
        while (currCopy) {
            currCopy->random = curr->random ? copies[curr->random] : nullptr;
            curr = curr->next;
            currCopy = currCopy->next;
        }
        return dummy.next;
    }
};
