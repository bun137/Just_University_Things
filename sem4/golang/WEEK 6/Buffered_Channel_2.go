package main

import "fmt"

func main() {

	ss := make(chan string, 2)
	ss <- "Hello"
	ss <- "World"

	ss <- "PESU" // lacks a receiver for the channel.

	fmt.Println(<-ss)
	fmt.Println(<-ss)
}

/*This means that all running goroutines (concurrently executing threads) are stuck waiting for something that can never happen,
effectively halting the program's progress.*/
//buffered channels prevent blocking when sending beyond their capacity,
