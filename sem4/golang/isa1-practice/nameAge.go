
package main
import "fmt"

func main() {
 var name string
 var age int
 fmt.Println("Enter your name and age:")
 fmt.Scanln(&name, &age)
 fmt.Printf("Name: %s\nAge: %d", name, age)
}
