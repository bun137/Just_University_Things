package main

import ("fmt"
        "time"
)

func main() {
              go MyFunction()
              //MyFunction()
              MyFunction()
}

func MyFunction() int {
              fmt.Println("Entering MyFunction")
              time.Sleep(5)
              fmt.Println("Exiting MyFunction")
              return 0  
}

