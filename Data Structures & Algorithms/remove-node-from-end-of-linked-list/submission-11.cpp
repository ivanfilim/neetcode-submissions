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
        ListNode dummy(0, head);
        ListNode* fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        ListNode* slow = &dummy;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        auto to_delete = slow->next;
        slow->next = slow->next->next;
        delete to_delete;
        return dummy.next;
    }
};
