package main

import (
	"bufio"
	"fmt"
	"os"
)

func apt(k, n int) int {
	mat := make([][]int, k+1)
	sum := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		mat[i] = make([]int, n+1)
		sum[i] = make([]int, n+1)
	}

	for height := 0; height <= k; height++ {
		for room := 1; room <= n; room++ {
			if height == 0 {
				mat[height][room] = room
				continue
			}

			for roomBelow := 1; roomBelow <= room; roomBelow++ {
				mat[height][room] += mat[height-1][roomBelow]
			}
		}
	}

	return mat[k][n]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int

	fmt.Fscanln(reader, &T)

	for T > 0 {
		var k, n int
		fmt.Fscanln(reader, &k)
		fmt.Fscanln(reader, &n)

		ans := apt(k, n)
		fmt.Fprintln(writer, ans)

		T--
	}
}
