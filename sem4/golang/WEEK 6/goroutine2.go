package main

import (
	"fmt"
)

func timesThree(number int, ch chan int) {
	result := number * 3
	fmt.Println(result)
	ch <- result
}

func main() {
	fmt.Println("We are executing a goroutine")
	ch := make(chan int)
	go timesThree(3, ch)
	result := <-ch
	fmt.Printf("The result is: %v", result)
}
