package main

import (
	"fmt"
	"strconv"
)

func main() {
	/*s := "hello, world"
	fmt.Println(len(s))
	fmt.Printf("%c\n", s[0])
	fmt.Printf("%c\n", s[7])
	fmt.Println(s[0:5])
	fmt.Println(s[:5])
	fmt.Println(s[7:])
	fmt.Println(s[:])
	fmt.Println(s[:5] + " students")*/

	x := "123"
	//strconv package //  converting string to numeric types and viceversa
	//strconv.Atoi(x)
	// Returns two values
	//converted integer
	// Error(if any)
	y, err := strconv.Atoi(x) //123 <nil>
	fmt.Println(y, err)

	z := strconv.Itoa(y) //123
	fmt.Println(z)       //"123"

	x = "123.45"
	z1, err := strconv.ParseFloat(x, 32)
	fmt.Println(z1)
}
