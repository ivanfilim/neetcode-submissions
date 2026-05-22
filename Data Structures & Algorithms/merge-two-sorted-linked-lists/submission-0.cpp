class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* resultList;

        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            resultList = new ListNode(list2->val);
            list2 = list2->next;
        } else if (list2 == nullptr) {
            resultList = new ListNode(list1->val);
            list1 = list1->next;
        } else if (list1->val < list2->val) {
            resultList = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            resultList = new ListNode(list2->val);
            list2 = list2->next;
        }

        ListNode* currNode = resultList;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                currNode->next = new ListNode(list2->val);
                list2 = list2->next;
            } else if (list2 == nullptr) {
                currNode->next = new ListNode(list1->val);
                list1 = list1->next;
            } else if (list1->val < list2->val) {
                currNode->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                currNode->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            currNode = currNode->next;
        } 

        return resultList;
    }
};