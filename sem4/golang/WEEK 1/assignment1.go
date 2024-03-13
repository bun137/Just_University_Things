package main

import "fmt"

func main() {
	var i, j, k = 2, 3, 4 // multiple assignment is ok in GO
	fmt.Println(i, j, k)
	i, j = j, i
	fmt.Println(i, j, k)
}
