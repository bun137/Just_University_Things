/*
a contract is a set of rules or specifications that define a particular behavior or capability.
Contracts are typically defined using interfaces in Go.
An interface in Go serves as a contract by specifying a set of method signatures
that a type must implement in order to satisfy the interface.
Any type that includes methods that match the signature of the methods declared in an
interface is said to implicitly implement that interface.
This allows for a flexible and expressive way of defining contracts in Go,
enabling polymorphic behavior and promoting code reusability.
By adhering to the rules of the contract (implementing the required methods),
different types can be treated uniformly if they satisfy the contract,
fostering a more modular and flexible codebase.

The ByteCounter type implements the io.Writer interface in Go,
even though it's not explicitly declared as the io.Writer interface type.

	The io.Writer interface in Go is defined as follows:

	type Writer interface {
	    Write(p []byte) (n int, err error)
	}

The Write method of the ByteCounter type matches the signature of the Write method in the io.Writer

	interface, which expects a byte slice and returns an integer and an error.

	As a result, the ByteCounter implicitly satisfies the io.Writer interface,
	as it implements the Write method according to the expected signature.

	while not explicitly named as such, the Write method of ByteCounter behaves as
	if it fulfills the contract of the io.Writer interface by adhering to the expected method signature,
	 allowing it to effectively implement the functionality defined by the interface.
*/
package main

import "fmt"

type ByteCounter int //This is a way to create a custom type in Go

func (c *ByteCounter) Write(p []byte) (int, error) {
	length := len(p);
	// len(p) = number of bytes in p ("Hello students")
	// now we convert this length, which is an integer, to our own type 'Bytecounter'
	byti := ByteCounter(length)
	// now the method 'Write' just means that you're adding the length of the the byte slice to the Bytecounter we called 'c'
	*c = *c + byti
	return len(p), nil
}

func main() {
	var c ByteCounter

	c.Write([]byte("hello students"))
	c.Write([]byte("hello cupcaki"))
	c.Write([]byte("hello penguinni"))

	fmt.Println(c) // len("hello students") + len("hello cupcaki") + len("hello penguinni")
}

func swap(a, b *int){
	temp := *a;
	*a = *b;
	*b = temp;
}
