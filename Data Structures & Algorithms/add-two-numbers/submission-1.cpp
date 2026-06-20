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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr, *curr = nullptr;
        int addition = 0;
        while (l1 || l2) {
            if (!curr) {
                curr = new ListNode();
                result = curr;
            } else {
                curr -> next = new ListNode();
                curr = curr -> next;
            }
            int addend1 = l1 ? (l1 -> val) : 0;
            int addend2 = l2 ? (l2 -> val) : 0;
            int sum = addend1 + addend2 + addition;
            curr -> val = sum % 10;
            addition = sum / 10;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        if (addition > 0) {
            curr -> next = new ListNode(addition);
        }
        return result;
    }
};
