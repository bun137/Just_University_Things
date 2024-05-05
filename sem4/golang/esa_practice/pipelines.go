package main

import "fmt"

func main() {
	countSquare := make(chan int, 4)
	squarePrint := make(chan int, 4)

	go func() {
		for i := 0; i < 5; i++ {
			countSquare <- i
		}
		close(countSquare)
	}()

	go func() {
		for i := range countSquare {
			squarePrint <- i * i
		}
		close(squarePrint)
	}()

	for i := range squarePrint {
		fmt.Println(i)
	}
}
