package main

import "fmt"

const boilingF = 212.0

func main() {
     
     var c = 5.0/9.0 * (boilingF - 32)

     fmt.Printf("boiling point = %g°F or %g°C\n", boilingF, c)

}