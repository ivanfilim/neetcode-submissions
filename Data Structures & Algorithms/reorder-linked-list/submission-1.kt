/**
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class Solution {
    fun reorderList(head: ListNode?): Unit {
        if (head == null) { return }
        var slow = head
        var fast = head
        while (fast?.next?.next != null) {
            slow = slow?.next
            fast = fast?.next?.next
        }
        var second = slow?.next
        slow?.next = null
        second = reversed(second)
        var first = head
        while (second!=null) {
            val nextFirst = first?.next
            val nextSecond = second?.next
            first?.next = second
            second.next = nextFirst
            second = nextSecond
            first = nextFirst
        }
    }

    fun reversed(head: ListNode?): ListNode? {
        var prev: ListNode? = null
        var curr: ListNode? = head
        while (curr != null) {
            val next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        }
        return prev
    }
}
