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
        auto curr = head;
        int count = 0;
        while (curr) {
            ++count;
            curr = curr->next;
        }
        count -= n;
        auto dummy = new ListNode(0, head);
        curr = dummy;
        for (int i = 0; i < count; ++i) {
            curr = curr->next;
        }
        auto toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
        auto toReturn = dummy->next;
        delete dummy;
        return toReturn;
    }
};
