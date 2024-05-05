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
	squari := square(10)
	fmt.Println(squari)
	negai := nega(10)
	fmt.Println(negai)
	muli := mul(10, 10)
	fmt.Println(muli)
}
