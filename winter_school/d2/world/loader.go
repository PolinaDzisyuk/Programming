package world

import (
	"os"
	"strings"
)

type Point struct{ X, Y int }

func LoadMaze(maze_00 string) ([][]rune, Point, Point, Point, error) {
	var maze [][]rune
	var start, end, key_p Point

	data, err := os.ReadFile(maze_00)
	if err != nil {
		return nil, Point{}, Point{}, Point{}, err
	}

	lines := strings.Split(string(data), "\n")
	for _, line := range lines {
		line := strings.TrimSpace(line)
		if len(line) == 0 {
			continue
		}
		maze = append(maze, []rune(line))

		for x := 0; x < len(maze); x++ {
			for y := 0; y < len(maze[x]); y++ {
				if maze[x][y] == '#' {
					maze[x][y] = '🧊'
				}
				if maze[x][y] == ' ' {
					maze[x][y] = '　'
				}
				if maze[x][y] == 'E' {
					maze[x][y] = '⛺'
				}
				if maze[x][y] == 'S' {
					maze[x][y] = '🏁'
				}
				if maze[x][y] == 'K' {
					maze[x][y] = '🔑'
				}
			}
		}

	}

	for x := 0; x < len(lines); x++ {
		for y := 0; y < len(lines[0]); y++ {
			if lines[x][y] == 'S' {
				start = Point{X: x, Y: y}
			}
		}
	}
	for x := 0; x < len(lines); x++ {
		for y := 0; y < len(lines[0]); y++ {
			if lines[x][y] == 'E' {
				end = Point{X: x, Y: y}
			}
		}
	}
	for x := 0; x < len(lines); x++ {
		for y := 0; y < len(lines[0]); y++ {
			if lines[x][y] == 'K' {
				end = Point{X: x, Y: y}
			}
		}
	}
	return maze, start, end, key_p, nil
}
