/*
Declare a structure in go:

	type structure_name struct{
		//struct definition
	}

//Method 1: // declare a structure variable

	type Person struct{
		Name string
		Age int
	}

var p1 Person

//method 2: // declare and also initiliaze the structure members
var p2  = Person{Name:"Bob",Age:34}

//method 3:
p3 := Person{Name:"Alice",Age:78}

//method 4:

	p5 := struct{
		ID int
		Name string
	}{ID:1001,Name:"Dev"}
*/
package main

import "fmt"

func main() {
	type Person struct {
		name string
		age  int
	}
	//assign the value to the struct
	p1 := Person{"John", 45}
	var p2 Person
	p2 = Person{name: "Sara", age: 29}
	fmt.Println(p1)
	fmt.Println(p2)

	fmt.Println(p2.age) // access the struct memeber values
	p2.age = 90
	p1.name = "KKKK"
	fmt.Println(p1)
	fmt.Println(p2)

	fmt.Println(p1.age == p2.age)

}
