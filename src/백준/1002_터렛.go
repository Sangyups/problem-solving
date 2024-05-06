package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(x1, y1, r1, x2, y2, r2 int) int {
	dist := math.Sqrt(math.Pow(float64(x1-x2), 2) + math.Pow(float64(y1-y2), 2))
	radius_diff := math.Abs(float64(r1 - r2))
	radius_sum := float64(r1 + r2)

	if dist > radius_sum {
		return 0
	} else if dist == radius_sum {
		return 1
	} else if radius_diff < dist && dist < radius_sum {
		return 2
	} else if dist == radius_diff {
		if dist == 0 {
			return -1
		}
		return 1
	} else {
		return 0
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int

	fmt.Fscanln(reader, &T)

	for T > 0 {
		var x1, y1, r1, x2, y2, r2 int
		fmt.Fscanln(reader, &x1, &y1, &r1, &x2, &y2, &r2)
		ans := solve(x1, y1, r1, x2, y2, r2)
		fmt.Fprintln(writer, ans)
		T -= 1
	}
}
