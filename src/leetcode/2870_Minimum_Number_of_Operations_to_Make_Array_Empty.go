package main

import "math"

func minOperations(nums []int) int {
	numCnt := make(map[int]int)
	for _, num := range nums {
		numCnt[num]++
	}

	cnt := 0
	for _, val := range numCnt {
		if val == 1 {
			return -1
		}

		cnt += int(math.Ceil(float64(val) / float64(3)))
	}

	return cnt
}
