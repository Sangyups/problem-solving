# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        a = l1.val
        b = l2.val
        curr_node = ListNode((a + b) % 10)
        initial_node = curr_node
        remainder = (a + b) // 10
        l1 = l1.next
        l2 = l2.next
        while l1 or l2 or remainder:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            new_node = ListNode((a + b + remainder) % 10)
            curr_node.next = new_node
            remainder = (a + b + remainder) // 10
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            curr_node = new_node

        return initial_node
