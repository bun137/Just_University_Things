package main

import (
	"fmt"
)

func produceResults(ch chan int) {
	ch <- 1
	ch <- 2
	//ch <- 3
	close(ch) // close the channel if nothing to produce
}

func main() {
	ch := make(chan int)
	go produceResults(ch)
	//time.Sleep(2 * time.Second)

	for i := 0; i < 3; i++ {
		select {
		case x, ok := <-ch: // x: value ; ok: true/false
			if ok {
				fmt.Println(x)
			} else {
				fmt.Println("channel closed")
			}
		}
	}
}
