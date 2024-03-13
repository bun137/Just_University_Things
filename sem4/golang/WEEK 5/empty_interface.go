/*
Empty Interface: The empty interface type interface{} is a special case
in Go that specifies an interface with no methods.
This means that any type satisfies the empty interface.
While it is powerful, its use should be carefully considered due to the loss
of type safety.
*/
package main

import "fmt"

func describe(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}

func main() {
	// Using the empty interface to accept values of any type
	describe(42)
	describe("Hello class!")
	//describe()
}
