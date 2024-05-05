package main

import "fmt"

func main() {
	string := "hi im shreya"
	fmt.Println(string)
	fmt.Println((len(string)))
	fmt.Println(string[0], string[8]) // prints ascii value of h and a
	fmt.Println(string[0:2])          // prints h = 0, i = 1
	fmt.Println(string[6:12])         // prints shreya
	fmt.Println(string[6:])           // prints shreya
	fmt.Println(string[:])            // prints hi im shreya
	fmt.Println(string[:5] + " this is fun")

}
