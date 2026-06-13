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
        ListNode *l = head, *r = head;
        while (n > 0) {
            r = r->next;
            --n;
        }

        ListNode* prev = nullptr;
        while (r) {
            prev = l;
            l = l->next;
            r = r->next;
        }

        ListNode *result, *toDelete;
        if (!prev) {
            toDelete = head;
            result = toDelete->next;
        } else {
            toDelete = prev->next;
            prev->next = toDelete->next;
            result = head;
        }

        delete toDelete;
        return result;
    }
};
