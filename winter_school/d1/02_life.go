package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

type Point struct {
	X int
	Y int
}

func seed(grid [][]int) {
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if rand.Float64() < 0.5 {
				grid[i][j] = 1
			}
		}
	}
}

func countNeighbors(grid [][]int, row, col int) int {
	h, w := len(grid), len(grid[0])
	cnt_neighbors := 0
	for i := -1; i <= 1; i++ {
		for j := -1; j <= 1; j++ {
			if i == 0 && j == 0 {
				continue
			}
			r := (row + i + h) % h
			c := (col + j + w) % w
			if grid[r][c] == 1 {
				cnt_neighbors += 1
			}
		}
	}
	return cnt_neighbors
}

func nextGen(current [][]int) [][]int {
	h, w := len(current), len(current[0])
	newGrid := make([][]int, h)
	for i := range newGrid {
		newGrid[i] = make([]int, w)
	}

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			Neighbors := countNeighbors(current, i, j)
			if true {
				Neighbors -= 1
				if Neighbors < 2 || Neighbors > 3 {
					newGrid[i][j] = 0
				} else {
					newGrid[i][j] = 1
				}
			} else {
				if Neighbors == 3 {
					newGrid[i][j] = 1
				} else {
					newGrid[i][j] = 0
				}
			}
		}
	}
	return newGrid
}

func printGrid(grid [][]int) {
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] > 0 {
				fmt.Print("\033[100m \033[0m")
			} else {
				fmt.Print("  ")
			}
		}
		fmt.Println()
	}
}

func SpawnGlider(maze [][]int, startX, startY int) {
	cells := []Point{
		{X: 0, Y: 1},
		{X: 1, Y: 2},
		{X: 2, Y: 0},
		{X: 2, Y: 1},
		{X: 2, Y: 2},
	}

	for _, c := range cells {
		nx, ny := startX+c.X, startY+c.Y

		if nx >= 0 && nx < len(maze) && ny >= 0 && ny < len(maze[0]) {
			maze[nx][ny] = 1
		}
	}
}

func main() {
	if len(os.Args) < 3 {
		fmt.Println("Пожалуйста, введите высоту и ширину клетки")
		return
	}

	h, err1 := strconv.Atoi(os.Args[1])
	w, err2 := strconv.Atoi(os.Args[2])
	if err1 != nil || err2 != nil {
		return
	}
	if h <= 0 || w <= 0 {
		return
	}

	grid := make([][]int, h)
	for i := range grid {
		grid[i] = make([]int, w)
	}

	seed(grid)
	SpawnGlider(grid, h/2, w/2)

	for {
		fmt.Print("\033[H\033[2J")
		printGrid(grid)
		grid = nextGen(grid)
		time.Sleep(100 * time.Millisecond)
	}
}
