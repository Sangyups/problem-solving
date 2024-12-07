package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func welcomeKit(N, T, P int, tShirts []int) (int, int, int) {
	tShirtBundle := 0

	for _, tShirt := range tShirts {
		if tShirt%T == 0 {
			tShirtBundle += (tShirt / T)
		} else {
			tShirtBundle += (tShirt/T + 1)
		}
	}

	return tShirtBundle, N / P, N % P
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, T, P int

	fmt.Fscanln(reader, &N)
	tShirts := make([]int, 6)

	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	numStrings := strings.Fields(line)

	for i, num := range numStrings {
		tShirts[i], _ = strconv.Atoi(num)
	}

	fmt.Fscanln(reader, &T, &P)

	tShirtBundle, penBundle, penIndividual := welcomeKit(N, T, P, tShirts)

	fmt.Fprintln(writer, tShirtBundle)
	fmt.Fprintln(writer, penBundle, penIndividual)
}
