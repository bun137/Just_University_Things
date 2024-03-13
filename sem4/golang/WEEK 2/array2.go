package main

import "fmt"

func main() {
	arr1 := [5]int{}              // 0 as defalut values [0 0 0 0 0]
	arr2 := [5]int{1, 2}          //[1 2 0 0 0]
	arr3 := [5]int{1, 2, 3, 4, 5} //[1 2 3 4 5]
	fmt.Println(arr1)
	fmt.Println(arr2)
	fmt.Println(arr3)
	// float - 0.0 , string - "" , int - 0

	arr4 := [5]int{1: 10, 2: 55} //[0 10 55 0 0]
	fmt.Println(arr4)

	arr6 := [...]int{10, 20, 30, 40, 50, 60, 70, 80, 90, 11, 22, 33, 44, 55, 66}
	fmt.Println(len(arr6)) // len() -> finds the length of the array

	// Nested Arrays // row length, col length
	var nested = [3][5]int{{1, 2, 3, 4, 5},
		{20, 30, 40, 50, 60},
		{11, 12, 13, 14, 15}}
	fmt.Println(nested)

}
