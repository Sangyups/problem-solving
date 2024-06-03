package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solution(arr []int) []int {
	ans := make([]int, 0)
	numMap := make(map[int]int)

	for _, elm := range arr {
		val := numMap[elm]
		if val > 0 {
			numMap[elm]--
			continue
		}
		numMap[elm*4/3]++
		ans = append(ans, elm)
	}

	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscanln(reader, &T)

	for i := 1; i <= T; i++ {
		var N int
		fmt.Fscanln(reader, &N)

		line, _ := reader.ReadString('\n')
		nums := strings.Fields(line)

		arr := make([]int, N*2)
		for idx, num := range nums {
			arr[idx], _ = strconv.Atoi(num)
		}

		ans := solution(arr)

		fmt.Fprintf(writer, "Case #%d:", i)
		for _, num := range ans {
			fmt.Fprintf(writer, " %d", num)
		}
		fmt.Fprintln(writer)
	}
}
