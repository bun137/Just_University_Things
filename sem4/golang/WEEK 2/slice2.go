package main

import "fmt"

func main() {
	months := [...]string{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec"}
	Q2 := months[4:7]
	fmt.Println(Q2) //["May","June","July"]// index starts at 0
	fmt.Println(len(Q2), cap(Q2))
	// The capacity of the new slice is determined by the distance between the first element
	//of the slice and the end of the underlying array

	sum := months[6:9]
	fmt.Println(sum)
	fmt.Println(len(sum), cap(sum))

	end := Q2[:4]
	fmt.Println(end)
	fmt.Println(len(end), cap(end))

	fmt.Printf("%T\n", months) // T - format specifier that gives you the type of the variable
	fmt.Printf("%T\n", Q2)

	// appending slices
	m1 := []string{"One", "Two", "Three"}
	m2 := []string{"Four", "Five", "Six"}

	m := append(m1, m2...)
	fmt.Println(m)
	//... is used to unpack the elements of the slice
}
