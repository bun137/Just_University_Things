/*
Declaring an array:
1. var keyword
var arry_name = [length]datatype{values}
or
var arry_name = [...]datatype{values}
2. :=
array_name := [length]datatype{values}
or
array_name := [...]datatype{values}
*/
package main

import "fmt"

func main() {
	var a [3]int // declaring array of 3 integers
	fmt.Println((a))
	fmt.Println(a[0], a[1], a[len(a)-1]) //[0 0 0]

	//var q [3]int = [3]int{1, 2, 3}
	var q = [3]int{1, 2, 3}              // declare & initialze
	fmt.Println(q[0], q[1], q[len(q)-1]) //[1 2 3]

	var r [3]int = [3]int{1, 2} //[1 2 0]
	fmt.Println(r)

	k := [...]int{99: -1}
	//Declares an array with 100 elements of type int with the value at index 99 initialized to -1
	fmt.Println(k[0])
	fmt.Println(k[len(k)-1])
	//Two arrays can be directly compared using the == operator
	// corresponding elements are equal
	a1 := [2]int{1, 2}
	b1 := [...]int{1, 2}
	c1 := [2]int{1, 4}
	fmt.Println(a1 == b1, a1 == c1, b1 == c1) //true false false
}
