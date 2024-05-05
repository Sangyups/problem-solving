package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

func solve(N big.Int, M big.Int) (*big.Int, *big.Int) {
	return new(big.Int).Div(&N, &M), new(big.Int).Mod(&N, &M)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N big.Int
	var M big.Int
	fmt.Fscanln(reader, &N, &M)

	ans1, ans2 := solve(N, M)

	fmt.Fprintln(writer, ans1)
	fmt.Fprintln(writer, ans2)
}
