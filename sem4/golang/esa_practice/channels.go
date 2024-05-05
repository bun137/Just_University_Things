package main

import "fmt"

func main() {
	ch := make(chan int)
	go func() {
		ch <- 1
	}()
	y := <-ch
	fmt.Println(y)

}
