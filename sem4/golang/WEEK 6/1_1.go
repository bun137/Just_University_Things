package main

import (
	"fmt"
)

func numbers() {
	for i := 0; i < 8; i++ {
		fmt.Println(i)
	}
}

func main() {
	fmt.Println("Main starting...")
	go numbers() // run without go keyword
	//time.Sleep(10 * time.Second)
	fmt.Println("Main finished...")

}
