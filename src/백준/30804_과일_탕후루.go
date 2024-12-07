package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var N int

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func tanghooru(arr []int) int {
	set := make(map[int]int)

	set[arr[0]] = 1

	i, j := 0, 0
	maxLen := 0

	for j < len(arr)-1 {
		nextNum := arr[j+1]
		maxLen = max(maxLen, j-i+1)

		_, exists := set[nextNum]
		if exists {
			j++
			set[nextNum]++
			continue
		}

		if len(set) < 2 {
			j++
			set[nextNum] = 1
			continue
		}

		cnt, _ := set[arr[i]]
		if cnt == 1 {
			delete(set, arr[i])
		} else {
			set[arr[i]]--
		}
		i++
	}

	maxLen = max(maxLen, j-i+1)
	return maxLen
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &N)

	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	stringNums := strings.Fields(line)

	arr := make([]int, N)
	for i, stringNum := range stringNums {
		num, _ := strconv.Atoi(stringNum)
		arr[i] = num
	}

	ans := tanghooru(arr)
	fmt.Fprintln(writer, ans)
}
