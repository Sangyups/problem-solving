package main

import (
	"container/heap"
)

type Pair struct {
	value int
	pos   int
}

type PairHeap []Pair

func (h PairHeap) Len() int {
	return len(h)
}

func (h PairHeap) Less(i, j int) bool {
	if h[i].value < h[j].value {
		return true
	} else if h[i].value > h[j].value {
		return false
	}
	return h[i].pos < h[j].pos
}

func (h PairHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *PairHeap) Push(element interface{}) {
	*h = append(*h, element.(Pair))
}

func (h *PairHeap) Pop() interface{} {
	old := *h
	n := len(old)
	element := old[n-1]
	*h = old[0 : n-1]
	return element
}

func getFinalState(nums []int, k int, multiplier int) []int {
	h := &PairHeap{}
	heap.Init(h)
	for i, num := range nums {
		pair := Pair{value: num, pos: i}
		heap.Push(h, pair)
	}

	for i := 0; i < k; i++ {
		m := heap.Pop(h).(Pair)
		m.value *= multiplier
		nums[m.pos] = m.value
		heap.Push(h, m)
	}
	return nums
}
