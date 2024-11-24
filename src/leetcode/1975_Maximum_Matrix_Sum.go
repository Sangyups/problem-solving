package main

func maxMatrixSum(matrix [][]int) int64 {
	n := len(matrix)
	negCnt := 0
	sum := int64(0)
	smallestAbs := 1_000_000

	for i := range n {
		for j := range n {
			curr := matrix[i][j]

			if curr < 0 {
				negCnt++
				smallestAbs = min(-curr, smallestAbs)
				sum -= int64(curr)
			} else {
				smallestAbs = min(curr, smallestAbs)
				sum += int64(curr)
			}

		}
	}

	if negCnt%2 == 0 {
		return sum
	}

	return sum - int64(smallestAbs)*2
}
