package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func fizzBuzz(s1, s2, s3 string) string {
	ansNum := 0

	if s1 != "Fizz" && s1 != "Buzz" && s1 != "FizzBuzz" {
		num, _ := strconv.Atoi(s1)
		ansNum = num + 3
	} else if s2 != "Fizz" && s2 != "Buzz" && s2 != "FizzBuzz" {
		num, _ := strconv.Atoi(s2)
		ansNum = num + 2
	} else {
		num, _ := strconv.Atoi(s3)
		ansNum = num + 1
	}

	if ansNum%15 == 0 {
		return "FizzBuzz"
	} else if ansNum%3 == 0 {
		return "Fizz"
	} else if ansNum%5 == 0 {
		return "Buzz"
	} else {
		return strconv.Itoa(ansNum)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s1, s2, s3 string

	fmt.Fscanln(reader, &s1)
	fmt.Fscanln(reader, &s2)
	fmt.Fscanln(reader, &s3)

	ans := fizzBuzz(s1, s2, s3)
	fmt.Fprintln(writer, ans)
}
