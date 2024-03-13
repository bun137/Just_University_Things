package main

import "fmt"

type Priority int8

func (p Priority) Stdring() string {
	switch p {
	case 0:
		return "low"
	case 1:
		return "high"
	}

	return "unknown"
}

func main() {
	var p Priority = 1

	// Uncomment the following two lines to see the error when
	// trying to assign two different types
	// var i int8 = 2
	// p = i

	fmt.Println(p.Stdring())         // "high" // method
	fmt.Println(Priority.Stdring(p)) // "high" // function
	fmt.Println(p)                  // "high" // type Stringer interface{
	//String() string - interfaces are implicit
	//}
}
