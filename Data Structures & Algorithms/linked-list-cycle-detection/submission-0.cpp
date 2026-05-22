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
    bool hasCycle(ListNode* head) {
        set<ListNode*> nodes;
        while (head) {
            if (nodes.find(head) != nodes.end()) {
                return true;
            }
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
};