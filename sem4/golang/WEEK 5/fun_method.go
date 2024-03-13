/*Functions:

Definition: Functions are independent blocks of code that perform specific tasks.
They are declared using the func keyword, followed by the function name,
parameter list (if any), and return type (if any).*/

/*package main

func add(x, y int) int {
	return x + y
}

func main() {
	result := add(5, 3)
	fmt.Println(result) // Output: 8
}*/
/*Operate independently without being attached to specific types.
Can take various data types as parameters and return different data types.
Useful for general-purpose calculations or operations.*/

/*
Methods:

Definition: Methods are functions attached to specific types
(structs, pointers to structs, interfaces).

	They define how you interact with and manipulate data of that type.
*/
package main

import (
	"fmt"
)

type User struct {
	name string
	age  int
}

func (u User) fullName() string { //(u User) - (<receiver_type> <receiver_name>)
	return fmt.Sprintf("%s, age %d", u.name, u.age)
}

func main() {
	//user := User{name: "Alice", age: 30}
	var u User
	u.name = "Alice"
	u.age = 45
	fullName := u.fullName()
	fmt.Println(fullName) // Output: Alice, age 30
}

/*Have a special receiver argument (<receiver_type> <receiver_name>) that specifies the type they operate on.
Can access and modify the fields of the receiver type.
Provide object-oriented-like behavior, even though Go doesn't have traditional classes.*/
