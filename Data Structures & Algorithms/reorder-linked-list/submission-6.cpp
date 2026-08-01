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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto list1 = head;
        auto list2 = reverseList(slow->next);
        slow->next = nullptr;
        while (list1 && list2) {
            auto next1 = list1 -> next;
            auto next2 = list2 -> next;
            list1->next = list2;
            list2->next = next1;
            list1 = next1;
            list2 = next2;
        }
    }
};
