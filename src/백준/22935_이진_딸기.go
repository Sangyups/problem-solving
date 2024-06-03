package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscanln(reader, &T)

	for T > 0 {
		var N int
		fmt.Fscanln(reader, &N)

		mod := (N-1)%28 + 1
		if mod > 15 {
			mod = 30 - mod
		}

		for i := 3; i >= 0; i-- {
			if (1<<i)&mod == 0 {
				fmt.Fprintf(writer, "V")
			} else {
				fmt.Fprintf(writer, "딸기")
			}
		}
		fmt.Fprintln(writer)
		T--
	}
}

