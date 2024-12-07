package main

func maxCount(banned []int, n int, maxSum int) int {
	bannedMap := make(map[int]bool)
	for _, banNum := range banned {
		bannedMap[banNum] = true
	}

	sum := 0
	cnt := 0

	for i := 1; i <= n; i++ {
		if bannedMap[i] {
			continue
		}

		if sum+i > maxSum {
			return cnt
		}

		sum += i
		cnt += 1
	}

	return cnt
}
