/* Go is a statically typed language - if you have declared a variable the type of the
variable is checked at compile time and also the variables must be expcitly declared
with their types.
Once if a variable is declared with a specific type, it cannot be later assigned a value
of a different type - ERROR */

package main

import "fmt"

func main() {
	a := "car" // var a = "car" // var a string = "car"
	fmt.Println(a)
	//b := "far" // NO ERROR
	//b = "far" //ERROR
	var b = "far" // NO ERROR
	fmt.Println("My city is " + b)
}
