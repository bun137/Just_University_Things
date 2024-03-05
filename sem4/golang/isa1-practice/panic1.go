package main
import "fmt"
func divide(a, b int) int {
    if b == 0 {
        panic("Divide by zero")
    }
    return a / b
}

func main() {
    fmt.Println(divide(10, 0))
    fmt.Println("This line will never execute")
}
