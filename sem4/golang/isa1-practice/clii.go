package main
import "fmt"
import "os"
func main(){
  fmt.Println("heyyyy starfishhh")
  fmt.Println("os.Args[0]:",os.Args[0])
  fmt.Println("os.Args[1]:",os.Args[1])
  fmt.Println("os.Args[2]:",os.Args[2])
  fmt.Println("os.Args[3]:",os.Args[3])
  fmt.Println(os.Args[0:])
  fmt.Println(os.Args[:3])
  fmt.Println(os.Args[2:3])
  fmt.Println(os.Args[2:4])
}
