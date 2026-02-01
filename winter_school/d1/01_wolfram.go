package main

import (
	"fmt"
	"os"
	"strconv"
)

func DecimalToBinary(n int) []int {
	bits := make([]int, 32)
	if n == 0 {
		bits = bits
	}
	if n != 0 {
		for i := 0; i < 32; i++ {
			bits[i] = n % 2
			n = n / 2
		}
		for i, j := 0, len(bits)-1; i > j; i, j = i+1, j-1 {
			bits[i], bits[j] = bits[j], bits[i]
		}
	}
	return bits
}

func printRow(row []int) {
	for i := 0; i < len(row); i++ {
		if row[i] == 1 {
			fmt.Print("\033[100m \033[0m")
		}
		if row[i] == 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

func nextGeneration(current []int) []int {
	new := make([]int, len(current))
	for i := 0; i < len(current)-1; i++ {
		if i == 0 {
			new[i] = 0 ^ current[i+1]
		}
		if i == len(current)-1 {
			new[i] = current[i-1] ^ 0
		}
		if i != 0 && i != len(current)-1 {
			new[i] = current[i-1] ^ current[i+1]
		}

	}
	return new
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Пожалуйста, введите число")
		return
	}
	n, err := strconv.Atoi(os.Args[1])
	if err != nil {
		return
	}
	bin := DecimalToBinary(n)
	fmt.Print(bin)

	row_0 := make([]int, 64)
	row := make([]int, len(row_0)+len(bin))
	for i := 0; i < len(bin); i++ {
		row[32+i] = bin[i]
	}

	for i := 0; i <= 32; i++ {
		printRow(row)
		row = nextGeneration(row)
	}
}
