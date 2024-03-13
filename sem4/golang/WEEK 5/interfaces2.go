package main

import "fmt"

// Defining an interface
type Shape interface {
	Area() float64
}

// Defining a struct type (Circle) and its method implementation
type Circle struct {
	Radius float64
}

func (c Circle) Area() (x ,y float64) {
	x:= 3.14 * c.Radius * c.Radius
	y:= c.Radius
	return
}

func main() {
	// Creating an instance of Circle
	c := Circle{Radius: 5}

	// Using the Area method through the Shape interface without explicitly stating Circle satisfies Shape interface
	var s Shape = c
	fmt.Println(s.Area()) // Output: 78.5
}
