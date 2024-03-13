package main

import (
	"fmt"
	"io"
	"strings"
)

func main() {
	r := strings.NewReader("Hello, Students!")

	b := make([]byte, 8)

	for {
		n, err := r.Read(b)
		fmt.Printf("n = %v err = %v b = %v\n", n, err, b)
		fmt.Printf("b[:n] = %q\n", b[:n])
		if err == io.EOF {
			break
		}
	}
	fmt.Printf("%s", r)
}

/*

r := strings.NewReader("Hello, Students!"): This line creates a new Reader object
 called r from the string "Hello, Students!" using the strings.NewReader function.
A Reader is an interface that represents a source of data that can be read from.

//b := make([]byte, 8): This line creates a slice of bytes called b with a length of 8.
	// A slice is like a flexible array that can grow or shrink in size.
	//In this case, it will be used to store data read from the Reader.

fmt.Printf("%s", r): This line prints the contents of the Reader object (r).
 However, since r is a strings.Reader, this doesn't actually do anything
 meaningful because strings.
Reader objects don't have a meaningful representation for printing.*/
