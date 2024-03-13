package main

import (
	"fmt"
	"time"
)

func myFunction() {
	for i := 0; i < 3; i++ {
		fmt.Println("my function: ", i)
	}
}
func anotherFunction() {
	for i := 4; i < 7; i++ {
		fmt.Println("another function: ", i)
	}
}

func main() {
	go myFunction()
	anotherFunction()
	time.Sleep(1 * time.Second)
}
