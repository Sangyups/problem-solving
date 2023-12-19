package main

func imageSmoother(img [][]int) [][]int {
	N := len(img)
	M := len(img[0])

	newImg := make([][]int, N)

	for i := 0; i < N; i++ {
		newImg[i] = make([]int, M)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			sum := 0
			cnt := 0
			for dx := -1; dx < 2; dx++ {
				for dy := -1; dy < 2; dy++ {
					nx := i + dx
					ny := j + dy

					if nx < 0 || nx >= N || ny < 0 || ny >= M {
						continue
					}

					sum += img[nx][ny]
					cnt++
				}
			}
			newImg[i][j] = sum / cnt
		}
	}

	return newImg
}

func main() {
}
