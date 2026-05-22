class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode* resultList;
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val < list2->val) {
            resultList = list1;
            list1 = list1->next;
        } else {
            resultList = list2;
            list2 = list2->next;
        }

        ListNode* currNode = resultList;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                currNode->next = list2;
                return resultList;
            } else if (list2 == nullptr) {
                currNode->next = list1;
                return resultList;
            } else if (list1->val < list2->val) {
                currNode->next = list1;
                list1 = list1->next;
            } else {
                currNode->next = list2;
                list2 = list2->next;
            }
            currNode = currNode->next;
        }

        return resultList;
    }
};