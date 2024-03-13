package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println((os.Args[0]))
	fmt.Println((os.Args[1]))
	fmt.Println((os.Args[2]))
	fmt.Println((os.Args[1:4]))
	fmt.Println((os.Args[1:]))
	fmt.Println((os.Args[:4]))

}
