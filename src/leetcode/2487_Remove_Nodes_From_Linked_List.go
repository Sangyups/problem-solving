/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
	arr := make([]ListNode, 0)
	for head.Next != nil {
		arr = append(arr, *head)
		head = head.Next
	}
	arr = append(arr, *head)

	ansArr := []ListNode{arr[len(arr)-1]}
	mx := head.Val
	for i := len(arr) - 2; i >= 0; i-- {
		if mx > arr[i].Val {
			continue
		}
		mx = arr[i].Val
		ansArr = append(ansArr, arr[i])
	}

	currNode := &ansArr[len(ansArr)-1]

	for i := len(ansArr) - 2; i >= 0; i-- {
		currNode.Next = &ansArr[i]
		currNode = &ansArr[i]
	}

	return &ansArr[len(ansArr)-1]
}
