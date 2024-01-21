package main

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)

	for i, num := range nums {
		if j, exists := numMap[target-num]; exists {
			return []int{i, j}
		}
		numMap[num] = i
	}

	return []int{}
}

