package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strings"
)

var N int

type MBTI struct {
	x int
	y int
	z int
	w int
}

func NewMBTI(mbti string) *MBTI {
	var x, y, z, w int

	if mbti[0] == 'E' {
		x = 1
	} else {
		x = 0
	}

	if mbti[1] == 'N' {
		y = 1
	} else {
		y = 0
	}

	if mbti[2] == 'T' {
		z = 1
	} else {
		z = 0
	}

	if mbti[3] == 'P' {
		w = 1
	} else {
		w = 0
	}

	return &MBTI{x, y, z, w}
}

func (m MBTI) getDistance(o MBTI) int {
	return int(math.Abs(float64(m.x-o.x)) + math.Abs(float64(m.y-o.y)) + math.Abs(float64(m.z-o.z)) + math.Abs(float64(m.w-o.w)))
}

func solution(mbtis []MBTI) int {
	ans := 50

	if N > 32 {
		return 0
	}

	for i := 0; i < N-2; i++ {
		for j := i + 1; j < N-1; j++ {
			for k := j + 1; k < N; k++ {
				distance := mbtis[i].getDistance(mbtis[j]) + mbtis[j].getDistance(mbtis[k]) + mbtis[k].getDistance(mbtis[i])

				if distance < ans {
					ans = distance
				}
			}
		}
	}

	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscanln(reader, &T)

	for T > 0 {
		fmt.Fscanln(reader, &N)

		text, _ := reader.ReadString('\n')
		students := strings.Fields(text)
		mbtis := make([]MBTI, 0)
		for _, student := range students {
			mbtis = append(mbtis, *NewMBTI(student))
		}
		fmt.Fprintln(writer, solution(mbtis))

		T--
	}
}
