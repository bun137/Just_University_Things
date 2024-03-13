/*
There are two ways to declare an array
 1. var keyword
    var array_name = [length]datatype{values} // the length is fixed
    or
    var array_name = [...]datatype{values}  // the length is inferred
    //[...] - compiler decides the length of the array based on the number of values

2. :=
array_name := [length]datatype{values}
or
array_name := [...]datatype{values}
*/
package main

import "fmt"

func main() {
	var a = [3]int{10, 20, 30}
	fmt.Println(a, a[0]) // indexing to access the elements
	a[0] = 66            // change the element of the array
	fmt.Println(a)
	//var b = [3]int{10, 20, 30, 80, 90} // ERROR
	//fmt.Println(b)

	a1 := [5]int{50, 60, 70}
	fmt.Println(a1)
}
