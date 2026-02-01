package algo

import (
	"math"
	"math/rand"
	"maze/entities"
	"maze/world"
)

func MonsterMove(monster *entities.Point, player world.Point, maze [][]rune) {
	directions := []entities.Point{{X: -1, Y: 0}, {X: 1, Y: 0}, {X: 0, Y: -1}, {X: 0, Y: 1}}
	var valid_mv []entities.Point
	var bestMove entities.Point

	for _, d := range directions {
		next_X := monster.X + d.X
		next_Y := monster.Y + d.Y

		if next_X >= 0 && next_X < len(maze) && next_Y >= 0 && next_Y < len(maze[0]) {
			if maze[next_X][next_Y] != '🧊' && maze[next_X][next_Y] != '🔑' {
				valid_mv = append(valid_mv, entities.Point{X: next_X, Y: next_Y})
			}
		}
	}

	if len(valid_mv) == 0 {
		return
	}

	if rand.Float64() < 0.2 {
		rand.Shuffle(len(valid_mv), func(i, j int) {
			valid_mv[i], valid_mv[j] = valid_mv[j], valid_mv[i]
		})
		bestMove = valid_mv[0]
	} else {
		bestDist := 999
		bestMove = valid_mv[0]
		for _, mv := range valid_mv {
			dist := int(math.Abs(float64(mv.X-player.X)) + math.Abs(float64(mv.Y-player.Y)))
			if dist < bestDist {
				bestDist = dist
				bestMove = mv
			}
		}
	}

	maze[monster.X][monster.Y] = '　'
	monster.X = bestMove.X
	monster.Y = bestMove.Y
	maze[monster.X][monster.Y] = '👻'

}
