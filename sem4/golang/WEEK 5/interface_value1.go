package main

import (
	"fmt"
)

type myinter interface {
	Method()
}

type S struct {
	Value string
}

func (s *S) Method() {}

type I int

func (i I) Method() {}

func main() {
	var inter_var myinter

	inter_var = &S{"Good afternoon"}
	fmt.Printf("Value: %v, Type: %T\n", inter_var, inter_var)
	//inter_var.Method()
	inter_var = I(100)
	fmt.Printf("Value: %v, Type: %T\n", inter_var, inter_var)
	//inter_var.Method()
}
