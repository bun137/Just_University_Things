package main

import "fmt"

func factori(n int) (f int) {
	if n == 0 {
		return 1
	}
	return n * factori(n-1)
}

func main() {
	fmt.Println(factori(10))
}
