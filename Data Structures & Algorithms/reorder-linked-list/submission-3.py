# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        while curr:
            next, curr.next = curr.next, prev
            prev, curr = curr, next
        return prev

    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head
        prevSlow = None
        while fast and fast.next:
            prevSlow = slow
            slow, fast = slow.next, fast.next.next
        if prevSlow:
            prevSlow.next = None
        
        list1, list2 = head, self.reverseList(slow)
        while list1 and list2:
            next1, next2 = list1.next, list2.next
            list1.next = list2
            list2.next = next1 if next1 else next2
            list1, list2 = next1, next2