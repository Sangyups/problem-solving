package main

func findMatrix(nums []int) [][]int {
	ans := make([][]int, 1)
	numCnt := make(map[int]int)

	for _, num := range nums {
		row := numCnt[num]

		if row >= len(ans) {
			emptyArr := make([]int, 0)
			ans = append(ans, emptyArr)
		}

		ans[row] = append(ans[row], num)
		numCnt[num]++
	}

	return ans
}
