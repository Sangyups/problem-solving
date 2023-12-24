package main

func minOperations(s string) int {
	cnt := 10005
	startingChars := []string{"0", "1"}

	for _, startingChar := range startingChars {
		currCnt := 0
		currChar := startingChar

		for _, char := range s {
			if currChar != string(char) {
				currCnt++
			}

			if currChar == "1" {
				currChar = "0"
			} else {
				currChar = "1"
			}
		}

		if currCnt < cnt {
			cnt = currCnt
		}
	}

	return cnt
}

