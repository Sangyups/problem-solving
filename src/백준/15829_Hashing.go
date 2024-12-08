package main

import (
	"bufio"
	"fmt"
	"os"
)

func hashing(s string) int {
	modular := 1_234_567_891
	hash := 0
	for i, c := range s {
		a := c - 'a' + 1
		n := 1
		for j := 0; j < i; j++ {
			n *= 31
			n %= modular
		}
		hash += n * (int(a) % modular)
	}

	return hash % modular
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var L int

	fmt.Fscanln(reader, &L)

	var s string
	fmt.Fscanln(reader, &s)

	ans := hashing(s)
	fmt.Fprintln(writer, ans)
}
