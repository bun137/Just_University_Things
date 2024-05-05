package main

import "fmt"

func incriOne() func() int {
	x := 1 // forget 0 indexing ig
	return func() int {
		x++
		return x
	}
}

func main() {
	incr := incriOne()
	fmt.Println(incr())
	fmt.Println(incr())
	fmt.Println(incr())
}
