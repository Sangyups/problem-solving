package main

import (
	"bufio"
	"fmt"
	"os"
)

func snail(A, B, V int) int {
	dailyHeight := A - B

	if (V-A)%dailyHeight == 0 {
		return (V-A)/dailyHeight + 1
	}
	return (V-A)/dailyHeight + 2
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var A, B, V int

	fmt.Fscanln(reader, &A, &B, &V)

	ans := snail(A, B, V)
	fmt.Fprintln(writer, ans)
}
