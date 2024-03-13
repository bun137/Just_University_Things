package main

import (
	"fmt"
	"time"
)

func sayHello(name string) {
	time.Sleep(1 * time.Second) // Simulate some work
	fmt.Println("Hello from", name)
}

func main() {
	go sayHello("Alice")            // Launch as a go routine
	fmt.Println("Hello from main!") // Continue main execution

	// Wait for a bit to ensure go routine has time to run
	time.Sleep(2 * time.Second)
}
