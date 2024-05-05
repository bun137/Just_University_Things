package main

import "fmt"

func square(n int) int {
	return n * n
}

func nega(n int) int {
	return -n
}

func mul(a, b int) int {
	return a * b
}

func main() {
	fmt.Println(square(5))
	fmt.Println(nega(5))
	fmt.Println(mul(5, 5))
}
