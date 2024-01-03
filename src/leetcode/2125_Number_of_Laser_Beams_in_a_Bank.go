package main

func numberOfBeams(bank []string) int {
	prevDeviceCnt := 0
	currDeviceCnt := 0
	ans := 0

	for i := 0; i < len(bank); i++ {
		for j := 0; j < len(bank[i]); j++ {
			if bank[i][j] == '1' {
				currDeviceCnt++
			}
		}
		ans += currDeviceCnt * prevDeviceCnt
		if currDeviceCnt != 0 {
			prevDeviceCnt = currDeviceCnt
		}
		currDeviceCnt = 0
	}

	return ans
}
