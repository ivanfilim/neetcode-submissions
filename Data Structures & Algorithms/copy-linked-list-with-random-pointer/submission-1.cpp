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
        if (!head) return nullptr;
        
        map<Node*, int> nodeToItsIdx;
        map<int, Node*> idxToItsRandom;

        Node* curr = head;
        int idx = 0;
        while (curr) {
            nodeToItsIdx[curr] = idx;
            idxToItsRandom[idx] = curr -> random;
            ++idx;
            curr = curr -> next;
        }

        Node* newHead = new Node(head -> val);
        Node* newCurr = nullptr;
        curr = head;
        idx = 0;
        map<int, Node*> newIdxToItsNode;
        while (curr) {
            if (!newCurr) {
                newCurr = newHead;
            } else {
                newCurr -> next = new Node(curr -> val);
                newCurr = newCurr -> next;
            }
            newIdxToItsNode[idx] = newCurr;
            ++idx;
            curr = curr -> next;
        }

        newCurr = newHead;
        idx = 0;
        while (newCurr) {
            Node* oldCurrRandom = idxToItsRandom[idx];
            newCurr -> random = oldCurrRandom ? newIdxToItsNode[nodeToItsIdx[oldCurrRandom]] : nullptr;
            ++idx;
            newCurr = newCurr -> next; 
        }

        return newHead;
    }
};
