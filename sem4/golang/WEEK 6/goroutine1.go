package main

import (
	"fmt"
	"time"
)

func timesThree(number int) {
	fmt.Println(number * 3)
}

func main() {
	fmt.Println("We are executing a goroutine")
	go timesThree(3)
	fmt.Println("Done!")
	time.Sleep(time.Second) // This sleep prevents the program for exiting
	// before the goroutine starts
}
