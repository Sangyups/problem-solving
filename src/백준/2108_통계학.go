package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var N int

func solution(arr []int) []int {
	ans := []int{0, 0, 0, 0}

	sort.Ints(arr)
	sum := 0
	maxCnt, currCnt := 0, 0
	currMode := []int{}

	for i, num := range arr {
		sum += num

		if i < len(arr)-1 && arr[i] == arr[i+1] {
			currCnt++
		} else if i < len(arr)-1 && arr[i] != arr[i+1] {
			if currCnt > maxCnt {
				maxCnt = currCnt
				currMode = []int{num}
			} else if currCnt == maxCnt {
				currMode = append(currMode, num)
			}
			currCnt = 0
		}
	}

	if currCnt > maxCnt {
		maxCnt = currCnt
		currMode = []int{arr[len(arr)-1]}
	} else if currCnt == maxCnt {
		currMode = append(currMode, arr[len(arr)-1])
	}

	ans[0] = int(math.Round(float64(sum) / float64(len(arr))))
	ans[1] = arr[len(arr)/2]
	if len(currMode) > 1 {
		ans[2] = currMode[1]
	} else {
		ans[2] = currMode[0]
	}
	ans[3] = arr[len(arr)-1] - arr[0]
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &N)
	arr := make([]int, 0)

	for i := 0; i < N; i++ {
		var num int
		fmt.Fscanln(reader, &num)
		arr = append(arr, num)
	}
	ansArr := solution(arr)

	for _, ans := range ansArr {
		fmt.Fprintln(writer, ans)
	}
}
