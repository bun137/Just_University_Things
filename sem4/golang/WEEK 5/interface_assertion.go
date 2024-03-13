/*the line var i interface{} = "hello" declares a variable i of type interface{}.
The value "hello" is then assigned to this interface variable.

The empty interface type interface{} is known as the interface type because
it doesn't specify any methods.
When a variable of the empty interface type is assigned a value,
it can hold values of any type. This makes it a versatile way to work with
values of different types in a single interface variable.
In the provided line, the string "hello" is assigned to the interface variable i.
Since string is a concrete type, it satisfies the empty interface and can be assigned to it.*/
//i.(Type) - i is an expression and T is the Type
package main

import "fmt"

func main() {
	var i interface{} = "32"

	s := i.(string)
	fmt.Println(s)

	s, ok := i.(string)
	fmt.Println(s, ok)

	f, ok := i.(string)
	fmt.Println(f, ok)

}
