package main

import (
	"bufio"
	"fmt"
	"os"
)

var N, M int
var trees []int

func getTree(height int) int {
	sum := 0

	for _, tree := range trees {
		if tree-height > 0 {
			sum += (tree - height)
		}
	}

	return sum
}

func solution() int {
	ans := 0

	minHeight := 0
	maxHeight := 1_000_000_000

	for minHeight <= maxHeight {
		midHeight := (minHeight + maxHeight) / 2
		totalTree := getTree(midHeight)
		if totalTree >= M {
			ans = midHeight
			minHeight = midHeight + 1
		} else {
			maxHeight = midHeight - 1
		}
	}

	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &N, &M)

	for i := 0; i < N; i++ {
		var num int
		fmt.Fscan(reader, &num)
		trees = append(trees, num)
	}

	fmt.Fprintln(writer, solution())
}
