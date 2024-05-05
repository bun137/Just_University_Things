package main

import "fmt"

func main() {
	var i interface{} = 1
	j := i.(int)
	fmt.Println(j)

}
