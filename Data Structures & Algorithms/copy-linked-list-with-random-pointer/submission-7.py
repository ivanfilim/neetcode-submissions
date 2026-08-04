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
        dummy = Node(0)
        curr, currCopy = head, dummy
        copies = {}
        while curr:
            currCopy.next = Node(curr.val)
            copies[curr] = currCopy.next
            curr, currCopy = curr.next, currCopy.next
        curr, currCopy = head, dummy.next
        while currCopy:
            currCopy.random = copies[curr.random] if curr.random else None
            curr, currCopy = curr.next, currCopy.next
        return dummy.next