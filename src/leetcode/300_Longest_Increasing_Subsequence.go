package main

func lowerBound(arr []int, key int) int {
	lo, hi := 0, len(arr)-1

	for lo <= hi {
		mid := (lo + hi) / 2

		if key <= arr[mid] {
			hi = mid - 1
		} else {
			lo = mid + 1
		}
	}

	return lo
}

func lengthOfLIS(nums []int) int {
	lis := []int{nums[0]}

	for i := 1; i < len(nums); i++ {
		num := nums[i]
		idx := lowerBound(lis, num)
		if idx >= len(lis) {
			lis = append(lis, num)
		} else {
			lis[idx] = num
		}
	}

	return len(lis)
}

