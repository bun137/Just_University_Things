package main

import (
	"fmt"
	"time"
)

func myFunction() {
	time.Sleep(2000 * time.Millisecond)
	for i := 0; i < 3; i++ {
		fmt.Println("my function: ", i)
	}
}
func anotherFunction() {
	time.Sleep(1000 * time.Millisecond)
	for i := 4; i < 7; i++ {
		fmt.Println("another function: ", i)
	}
}

func main() {
	go myFunction()
	go anotherFunction()
	time.Sleep(7 * time.Second)
	fmt.Println("Main Exited")
}
