/*
	os package

provides a platform-independent interface to operating system functionality
It allows you to perform operations related to the os, environment variables, command line args and
many more.
COMMAND LINE ARGUMENTS
*/
package main

import (
	"fmt"
	"os"
)

func main() {
	args1 := os.Args
	args2 := os.Args[1:4] // os.Args variable that provides access to the command line args
	fmt.Println(args1)
	fmt.Println(args2)

}
