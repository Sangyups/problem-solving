package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type point struct {
	x int
	y int
}

var N, M int
var mat [][]int
var visited [][]int
var dx = [4]int{-1, 1, 0, 0}
var dy = [4]int{0, 0, -1, 1}

func bfs(sx, sy int) int {
	ans := 0
	startingPoint := point{sx, sy}
	visited[sx][sy] = 1
	q := make([]point, 0)
	q = append(q, startingPoint)

	for len(q) > 0 {
		currPoint := q[0]
		q = q[1:]

		cx, cy := currPoint.x, currPoint.y

		for i := 0; i < 4; i++ {
			nx := cx + dx[i]
			ny := cy + dy[i]

			if nx < 0 || nx >= N || ny < 0 || ny >= M {
				continue
			}
			if mat[nx][ny] == 1 || visited[nx][ny] == 1 {
				continue
			}

			if mat[nx][ny] == 2 {
				ans++
			}

			visited[nx][ny] = 1
			q = append(q, point{nx, ny})
		}
	}

	return ans
}
func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &N, &M)

	mat = make([][]int, N)
	visited = make([][]int, N)
	var sx, sy int
	for i := 0; i < N; i++ {
		text, _ := reader.ReadString('\n')
		row := strings.TrimSpace(text)
		mat[i] = make([]int, M)
		visited[i] = make([]int, M)
		for j, char := range row {
			if char == 'O' {
				mat[i][j] = 0
			} else if char == 'X' {
				mat[i][j] = 1
			} else if char == 'P' {
				mat[i][j] = 2
			} else {
				sx, sy = i, j
			}
			visited[i][j] = 0
		}
	}
	ans := bfs(sx, sy)
	if ans == 0 {
		fmt.Fprintln(writer, "TT")
	} else {
		fmt.Fprintln(writer, ans)
	}
}
