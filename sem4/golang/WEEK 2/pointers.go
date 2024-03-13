/*& - address operator
* - Deferencing operator*/
package main

import "fmt"

func main() {
	x := 1
	y := 2
	p := &x //p is a pointer to an integer *int
	fmt.Println(p)
	fmt.Println(*p)
	*p = 2
	fmt.Println(x)

	q := &x
	fmt.Println(p == q)

	r := &y
	fmt.Println(p == r)
}
