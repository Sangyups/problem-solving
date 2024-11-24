package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var V int

type Pair struct {
	Node     int
	Distance int
}

func bfs(start int, mat [][]Pair) (int, int) {
	startNode := Pair{Node: start, Distance: 0}
	visited := make([]int, V+1)
	visited[start] = 1

	maxDistance := 0
	maxNode := start

	q := make([]Pair, 1)
	q = append(q, startNode)

	for len(q) > 0 {
		curr := q[0]
		q = q[1:]

		if maxDistance < curr.Distance {
			maxDistance = curr.Distance
			maxNode = curr.Node
		}

		for _, node := range mat[curr.Node] {
			nextDistance := curr.Distance + node.Distance
			nextNode := node.Node

			if visited[nextNode] == 1 {
				continue
			}

			visited[nextNode] = 1
			q = append(q, Pair{Node: nextNode, Distance: nextDistance})
		}
	}

	return maxNode, maxDistance
}

func diameterOfTree(mat [][]Pair) int {
	start := 1
	dest, _ := bfs(start, mat)
	_, diameter := bfs(dest, mat)

	return diameter
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanln(reader, &V)
	mat := make([][]Pair, V+1)

	for i := 1; i <= V; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		row := strings.Fields(line)

		arr := make([]int, 0)

		for _, char := range row {
			if char == "-1" {
				break
			}

			num, _ := strconv.Atoi(char)
			arr = append(arr, num)
		}

		node := arr[0]
		mat[node] = make([]Pair, 0)
		for j := 1; j < len(arr); j += 2 {
			mat[node] = append(mat[node], Pair{Node: arr[j], Distance: arr[j+1]})
		}
	}

	ans := diameterOfTree(mat)
	fmt.Fprintln(writer, ans)
}
