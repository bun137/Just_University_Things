package main

import "fmt"

func main() {
	ascii := 's' // this prints the ascii value of s
	fmt.Println(ascii)
	unicode := 's' // this prints the unicode value of s
	fmt.Println(unicode)
	newline := '\n' // this prints the newline character

	fmt.Printf("%d %[1]c %[1]q\n", ascii)
	fmt.Printf("%d %[1]c %[1]q\n", unicode)
	fmt.Printf("%d %[1]c %[1]q\n", newline)

}
