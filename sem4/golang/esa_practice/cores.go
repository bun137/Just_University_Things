package main

import (
	"fmt"
	"runtime"
)

func main() {
	currentValue := runtime.GOMAXPROCS(0)
	fmt.Printf("Current GOMAXPROCS value: %d\n", currentValue)
	maxCores := runtime.NumCPU()
	fmt.Printf("maxCores value: %d\n", maxCores)
}
