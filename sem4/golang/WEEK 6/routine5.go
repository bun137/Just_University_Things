package main

import (
	"fmt"
	"time"
)

func sayHello(name string, ch chan string) {
	time.Sleep(1 * time.Second) // Simulate some work
	fmt.Println("Hello from", name)
	ch <- "Finished greeting " + name // Send message to channel
}

func main() {
	ch := make(chan string) // Create a channel

	go sayHello("Alice", ch) // Launch as a go routine

	// Receive message from the go routine
	greeting := <-ch
	fmt.Println(greeting)

	// Wait for a bit to ensure go routine has time to run
	time.Sleep(2 * time.Second)
}

/*We create a channel (ch) to enable communication between functions.
The sayHello function sends a message ("Finished greeting...") to the channel after its work.
The main function receives the message from the channel using the <- operator.
Both functions can continue after communication, running asynchronously.*/
