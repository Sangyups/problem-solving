package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var N int

func solution(difficulties []int) int {
	totalCnt := len(difficulties)
	excludeCnt := int(math.Round(float64(totalCnt) * 0.15))

	sort.Ints(difficulties)

	sum := 0

	for i := excludeCnt; i < totalCnt-excludeCnt; i++ {
		sum += difficulties[i]
	}

	if sum == 0 {
		return 0
	}

	return int(math.Round(float64(sum) / float64(totalCnt-(excludeCnt*2))))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	defer writer.Flush()

	fmt.Fscanln(reader, &N)

	difficulties := make([]int, 0)
	for i := 0; i < N; i++ {
		var num int
		fmt.Fscanln(reader, &num)
		difficulties = append(difficulties, num)
	}

	ans := solution(difficulties)
	fmt.Fprintln(writer, ans)
}

