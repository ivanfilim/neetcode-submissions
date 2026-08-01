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
        map<Node*, Node*> copy;
        Node dummy(0);
        Node* curr = head;
        Node* currCopy = &dummy;
        while (curr) {
            currCopy->next = new Node(curr->val);
            currCopy = currCopy->next;
            copy[curr] = currCopy;
            curr = curr->next;
        }
        curr = head;
        currCopy = dummy.next;
        while (curr) {
            currCopy->random = curr->random ? copy[curr->random] : nullptr;
            curr = curr->next;
            currCopy = currCopy->next;
        }
        Node* headCopy = dummy.next;
        return headCopy;
    }
};
