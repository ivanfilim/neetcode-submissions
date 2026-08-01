"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head
        dummy = Node(0)
        newCurr = dummy
        m = {}
        while curr:
            newCurr.next = Node(curr.val)
            newCurr = newCurr.next
            m[curr] = newCurr
            curr = curr.next
        curr = head
        newCurr = dummy.next
        while curr:
            newCurr.random = None if not curr.random else m[curr.random]
            curr = curr.next
            newCurr = newCurr.next
        return dummy.next