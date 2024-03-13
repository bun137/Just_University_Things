/*
* What is a goroutine?
it is managed by the Go runtime rather than the operating system.
It is lightweight thread managed by the Go/Golang runtime,
independently executed function that has its own call stack.

* What is a channel?
A channel is a communication mechanism that enables one goroutine to send values to another goroutine.
it uses the arrow operator which indicates data flow. <-

By default sender and receiver will block if the other side is not ready
*/
package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan string)

	go func() {
		fmt.Println(time.Now(), "taking a nap")

		time.Sleep(2 * time.Second)

		ch <- "hello"
	}()

	fmt.Println(time.Now(), "waiting for message")

	v := <-ch

	fmt.Println(time.Now(), "received", v)
}
