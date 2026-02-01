package entities

type Point struct{ X, Y int }

func GetNewPosition(history []Point, playerPos Point) []Point {
	history = append(history, playerPos)
	if len(history) > 5 {
		history = history[1:]
	}
	return history
}
