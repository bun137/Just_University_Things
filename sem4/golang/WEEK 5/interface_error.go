package main

import (
	"fmt"
	"strconv"
	"time"
)

type MyError struct {
	When time.Time
	What string
}

// In Go, the Error() method is a special method that defines how an error is represented as a string.
func (e MyError) Error() string {
	return fmt.Sprintf("At %v, %s", e.When, e.What)
}

// The run() function serves as a simple example of generating a custom error.
// This function simulates a task that might fail and returns an error message.
// t doesn't perform any actual work besides creating and returning an error.
// The function declares a return type of error.
// This means it can return an object that implements the error interface, allowing it to signal potential issues.
func run() error {
	return MyError{time.Now(), "it didn't work"}
}

func main() {

	i, err := strconv.Atoi("42")
	if err != nil {
		fmt.Printf("couldn't convert number: %v\n", err)
		return
	}
	fmt.Println("Converted integer:", i)

	if blah := run(); blah != nil {
		fmt.Println(blah)
	}

}

/*In Go, the Error() method is a special method that defines how an error
is represented as a string. When you try to print an error using fmt.Println
or similar functions, this method is automatically called
 to get the error's message.

 Customizable Error Messages: By defining the Error() method, you can control
 how your custom errors are displayed, providing more informative and
 context-specific messages.

Integration with Error Handling: Go's error handling mechanisms rely on the Error()
 method to identify and manage errors consistently.
Key Point: The Error() method is essential for representing errors in a human-readable
 and informative way, making error handling and debugging more effective.
*/
