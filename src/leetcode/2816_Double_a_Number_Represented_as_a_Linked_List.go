/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverse(head *ListNode) *ListNode {
	var prev *ListNode
	curr := head

	for curr != nil {
		curr, prev, curr.Next = curr.Next, curr, prev
	}

	return prev
}

func doubleIt(head *ListNode) *ListNode {
	newHead := reverse(head)

	temp := &ListNode{0, newHead}
	carry := 0

	for temp != nil {
		tempMul := temp.Val*2 + carry
		if tempMul >= 10 {
			carry = 1
		} else {
			carry = 0
		}
		temp.Val = tempMul % 10
		temp = temp.Next
	}

	ans := reverse(newHead)

	if carry == 1 {
		return &ListNode{1, ans}
	}

	return ans
}
