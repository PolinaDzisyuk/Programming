package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sum := 0
	var ans float64

	if len(os.Args) < 2 {
		fmt.Println("Пожалуйста, введите число")
		return
	}

	N, err := strconv.Atoi(os.Args[1])
	if err != nil {
		return
	}

	a := make([]int, N)
	for i := 0; i < N; i++ {
		a[i] = i * i
		sum += a[i]
	}

	a = append(a, sum)
	var filtered []int
	for i := 0; i < N+1; i++ {
		if a[i]%3 == 0 {
			filtered = append(filtered, a[i])
		}
	}

	var q float64 = float64(len(a))
	var w float64 = float64(len(filtered))
	ans = 100 - (w / q * 100)
	fmt.Printf("[a] = %v\n", a)
	fmt.Printf("[filtered] = %v\n", filtered)
	fmt.Printf("[ans] = %v\n", ans)
}
