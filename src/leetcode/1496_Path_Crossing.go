package main

type Point struct {
	x int
	y int
}

func (p *Point) MoveX(value int) {
	p.x += value
}

func (p *Point) MoveY(value int) {
	p.y += value
}

func isPathCrossing(path string) bool {
	currPosition := Point{0, 0}
	visited := map[Point]bool{}
	visited[currPosition] = true

	for _, p := range path {
		if p == 'N' {
			currPosition.MoveY(1)
		} else if p == 'E' {
			currPosition.MoveX(1)
		} else if p == 'S' {
			currPosition.MoveY(-1)
		} else {
			currPosition.MoveX(-1)
		}

		if visited[currPosition] {
			return true
		}

		visited[currPosition] = true
	}

	return false
}
