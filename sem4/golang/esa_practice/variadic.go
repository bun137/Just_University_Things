package main

import "fmt"

func mul(val ...int) int {
	var result int
	for i, v := range val {
		if i == 0 {
			result = v
		} else {
			result *= v
		}
	}
	return result
}

func main() {
	fmt.Println(mul(1, 2, 3, 4, 5))
	fmt.Println(mul(1, 2))
}
