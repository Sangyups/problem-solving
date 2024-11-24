package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type EdgeMinHeap []Edge

var v, e int
var root []int
var rank []int

func (h EdgeMinHeap) Len() int {
	return len(h)
}

func (h EdgeMinHeap) Less(i, j int) bool {
	return h[i].Weight < h[j].Weight
}

func (h EdgeMinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *EdgeMinHeap) Push(element interface{}) {
	*h = append(*h, element.(Edge))
}

func (h *EdgeMinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	element := old[n-1]
	*h = old[0 : n-1]
	return element
}

type Edge struct {
	X      int
	Y      int
	Weight int
}

func find(x int) int {
	if root[x] == x {
		return root[x]
	}

	root[x] = find(root[x])
	return root[x]
}

func unionFind(x, y int) bool {
	if root == nil {
		root = make([]int, v+1)
		rank = make([]int, v+1)
		for i := 1; i <= v; i++ {
			root[i] = i
		}
	}

	x = find(x)
	y = find(y)

	if x == y {
		return true
	}

	if rank[x] < rank[y] {
		root[x] = y
	} else if rank[x] > rank[y] {
		root[y] = x
	} else {
		rank[x]++
		root[y] = x
	}

	return false
}

func minimumSpanningTree(edges []Edge) int {
	edgeMinHeap := EdgeMinHeap(edges)
	heap.Init(&edgeMinHeap)

	mstWeight := 0

	for edgeMinHeap.Len() > 0 {
		minEdge := heap.Pop(&edgeMinHeap).(Edge)

		x, y := minEdge.X, minEdge.Y

		if unionFind(x, y) {
			continue
		}

		mstWeight += minEdge.Weight
	}

	return mstWeight
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanf(reader, "%d %d\n", &v, &e)

	edges := make([]Edge, e)
	for i := 0; i < e; i++ {
		var x, y, w int
		fmt.Fscanf(reader, "%d %d %d\n", &x, &y, &w)

		edges[i] = Edge{
			X:      x,
			Y:      y,
			Weight: w,
		}
	}

	ans := minimumSpanningTree(edges)
	fmt.Fprintln(writer, ans)
}
