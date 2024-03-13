package main

import "fmt"

func produceResults(ch chan int) {
	ch <- 10
	ch <- 20
	//So what happens if you produce more values than you receive like so?
	//ch <- 30 you will miss out on the extra value
}

func main() {
	ch := make(chan int)
	go produceResults(ch)

	var result int
	result = <-ch
	fmt.Println(result)
	result = <-ch
	fmt.Println(result)
}

/*What if it’s the opposite, you try to receive one more value than you actually get?
At this point, your code will deadlock, like so: fatal error: all goroutines are asleep - deadlock!. Your code will never finish as that value will never arrive.

The lesson here is that you need to keep track of how many results you might get and only try to receive that many.*/
