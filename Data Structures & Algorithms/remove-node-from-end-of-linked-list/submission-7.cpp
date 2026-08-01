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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0, head);
        
        auto slow = dummy;
        auto fast = dummy;
        
        for (int i = 0; i <= n; ++i)
            fast = fast->next;
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node = slow->next;
        slow->next = node->next;
        delete node;

        head = dummy->next;
        delete dummy;
        return head;
    }
};
