package main

import (
	"fmt"
)

func main() {
	// Unbuffered channel - sender waits
	unbufferedCh := make(chan int)
	go func() {
		unbufferedCh <- 10 // Sender waits here
	}()
	fmt.Println(<-unbufferedCh) // Receiver receives

	// Buffered channel - sender doesn't wait
	bufferedCh := make(chan int, 2) // Buffer size 2
	go func() {
		bufferedCh <- 20 // Sender doesn't wait
		bufferedCh <- 30
	}()
	fmt.Println(<-bufferedCh) // Receiver receives first item
	fmt.Println(<-bufferedCh) // Receiver receives second item
}
