/* deadlock state: This means that all running goroutines (concurrently executing threads)
 are stuck waiting for something that will never happen,
effectively halting the program's progress.

The below program gives and error as no go routine sending any values to this channel,
 leading to all goroutines being "asleep" and waiting indefinitely.*/

/*package main

import "fmt"

func main() {

	ss := make(chan string, 2)

	fmt.Println(<-ss)
	fmt.Println(<-ss)

	close(ss)
}*/

/*Correct Program
package main

import "fmt"

func main() {
    ss := make(chan string, 2)

    // Send some values before closing the channel
    ss <- "Hello"
    ss <- "World"

    fmt.Println(<-ss) // Receive "Hello"
    fmt.Println(<-ss) // Receive "World"

    close(ss) // Close the channel after sending values
}*/

/*Handle the closed channel*/

package main

import "fmt"

func main() {
	ss := make(chan string, 2)
	ss <- "PESUEC"
	ss <- "PESURR"

	close(ss) // Close the channel immediately
	select {
	case msg, ok := <-ss:
		if ok {
			// Inside the loop, receive and print values until the channel is closed
			for ok {
				fmt.Println(msg)
				msg, ok = <-ss
			}
			fmt.Println("All values received")
		} else {
			fmt.Println("Channel closed")
		}
	default:
		fmt.Println("Channel already closed") // Not necessary here
	}
}

/*Alternative approach:
for {
	msg, ok := <-ss
	if ok {
		fmt.Println(msg)
	} else {
		fmt.Println("Channel closed, all values received")
		break // Exit the loop when there are no more values
	}
}*/
