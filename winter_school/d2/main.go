package main

import (
	"fmt"
	"maze/algo"
	"maze/entities"
	"maze/world"
	"os"
	"os/exec"
	"time"
)

type Point struct{ X, Y int }

func main() {
	var history []entities.Point

	maze, start, end, key_p, error := world.LoadMaze("world/maze_01.txt")

	player := start

	monster := entities.Point{X: 8, Y: 17}

	key := 0

	if error != nil {
		return
	}
	fmt.Printf("%v %v\n", start, end)

	fmt.Printf("%v", player)

	for {
		fmt.Print("\033[H\033[2J")

		maze[player.X][player.Y] = '🐧'
		maze[monster.X][monster.Y] = '👻'

		for _, row := range maze {
			fmt.Println(string(row))
		}

		sttyConfig := exec.Command("stty", "-F", "/dev/tty", "cbreak", "min", "1", "-echo")
		sttyConfig.Run()

		defer exec.Command("stty", "-F", "/dev/tty", "sane").Run()

		start := time.Now()
		move := false
		var b = make([]byte, 3)
		os.Stdin.Read(b)
		if b[0] == 'q' {
			break
		}

		old_X, old_Y := player.X, player.Y
		playerPos := entities.Point{X: old_X, Y: old_Y}

		switch b[0] {
		case 'w':
			if player.X-1 >= 0 && maze[player.X-1][player.Y] != '🧊' {
				player.X -= 1
				move = true
			}

		case 'a':
			if player.Y-1 >= 0 && maze[player.X][player.Y-1] != '🧊' {
				player.Y -= 1
				move = true
			}

		case 'd':
			if player.Y+1 < len(maze[0]) && maze[player.X][player.Y+1] != '🧊' {
				player.Y += 1
				move = true
			}

		case 's':
			if player.X+1 < len(maze) && maze[player.X+1][player.Y] != '🧊' {
				player.X += 1
				move = true
			}

		case 't':
			if len(history) > 0 {
				new_X, new_Y := player.X, player.Y

				lastIndex := len(history) - 1
				playerPos = history[lastIndex]

				player.X, player.Y = playerPos.X, playerPos.Y

				maze[new_X][new_Y] = '　'
				maze[player.X][player.Y] = '🐧'
				history = history[:lastIndex]
			} else {
				continue
			}
		}
		if maze[player.X][player.Y] == '🔑' {
			key = 1
		}

		if maze[player.X][player.Y] == '⛺' && key == 1 {
			fmt.Println("Поздравляю! Ты вернулся домой!")
			elapsed := time.Since(start)
			fmt.Printf("Прошло времени: %v\n", elapsed)
			time.Sleep(2 * time.Second)
			return
		}

		if move {
			history = entities.GetNewPosition(history, playerPos)
			if old_X != 1 || old_Y != 1 {
				maze[old_X][old_Y] = '　'

			} else {
				maze[old_X][old_Y] = '🏁'

			}
			if old_X == key_p.X || old_Y == key_p.Y {
				maze[old_X][old_Y] = '🔑'

			}

			if monster.X == player.X && monster.Y == player.Y {
				for _, row := range maze {
					maze[player.X][player.Y] = '💀'
					fmt.Println(string(row))
				}
				fmt.Print("\a")
				fmt.Println("Game over")
				return
			}

			algo.MonsterMove(&monster, player, maze)
			if monster.X == player.X && monster.Y == player.Y {
				fmt.Print("\a")
				fmt.Println("Game over")
				time.Sleep(2 * time.Second)
				return
			}
		}

		for _, row := range maze {
			fmt.Println(string(row))
		}
	}
}
