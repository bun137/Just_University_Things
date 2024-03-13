package main

import "fmt"

func main() {
	var num1 int = 10
	fmt.Println(num1)
	var num2 = 999
	fmt.Println(num2)
	num3 := 888
	fmt.Println(num3)
	num3 = 777
	fmt.Println(num3)
	//num3 = " Hello"
	//fmt.Println(num3)
	var name, age = "PESU", 50
	fmt.Println(name, age)
}

// in go, you cannot change the type of variable after it's declared
