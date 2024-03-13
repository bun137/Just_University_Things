package main

import "fmt"

func main() {
	// create a slice
	s1 := []int{10, 20, 30, 40, 50, 60, 70}
	fmt.Println(s1)
	fmt.Println(s1[1:4])

	// create a slice with make(datatype,length,capacity)
	s2 := make([]int, 3, 5) // Length:3 , Capacity: 5
	fmt.Println(s2)
	fmt.Println(len(s2), cap(s2))

	// Appending elements to the slice
	s3 := append(s2, 4, 5, 6, 7, 8, 9, 10, 11)
	fmt.Println(s3)
	fmt.Println(len(s3), cap(s3))

	//modify the elements of the slice
	s3[4] = 999
	fmt.Println(s3)

	// Iterating over the slice using range
	//method 1:
	for i := 0; i < len(s3); i++ {
		fmt.Println(i, ":", s3[i])
	}
	//method 2:
	for index, value := range s3 {
		fmt.Println(index, value)
	}

}
