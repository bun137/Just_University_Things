package main

import "fmt"

func main() {
	ch := make(chan int, 2)
	//Creates a buffered channel named ch that can hold up to 2 integers.
	ch <- 1 //ch <- 1: Sends the integer 1 to the ch channel.
	ch <- 2 //ch <- 2: Sends the integer 2 to the ch channel.

	fmt.Println(<-ch) //Receives an integer from the ch channel and prints it. Since two values were sent, this will print 1.
	fmt.Println(<-ch) // Receives another integer from the ch channel and prints it. This will print 2.
	//Creates another buffered channel named ss that can hold up to 2 strings.
	ss := make(chan string, 2)
	ss <- "Hello"     //Sends the string "Hello" to the ss channel.
	ss <- "World"     // Sends the string "World" to the ss channel.
	fmt.Println(<-ss) // Receives a string from the ss channel and prints it. Since two values were sent, this will print "Hello".
	fmt.Println(<-ss) //Receives another string from the ss channel and prints it. This will print "World".
}
