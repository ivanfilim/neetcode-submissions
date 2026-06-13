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
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            ++length;
            curr = curr->next;
        }
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < length - n; ++i) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* result = head;
        if (!prev) result = curr->next;
        else prev->next = curr->next;
        delete curr;
        return result;
    }
};
