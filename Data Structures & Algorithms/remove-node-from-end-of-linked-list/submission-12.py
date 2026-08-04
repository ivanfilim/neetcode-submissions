# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy, fast = ListNode(0, head), head
        for i in range(n):
            fast = fast.next
        slow = dummy
        while fast:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next