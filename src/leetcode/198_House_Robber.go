package main

func rob(nums []int) int {
	dp := make([]int, len(nums))

	dp[0] = nums[0]

	if len(dp) > 1 {
		dp[1] = max(nums[0], nums[1])
	}

	for i, num := range nums {
		if i < 2 {
			continue
		}

		dp[i] = max(dp[i-2]+num, dp[i-1])
	}

	return dp[len(dp)-1]
}

