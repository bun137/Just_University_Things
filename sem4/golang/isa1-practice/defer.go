package main
import "fmt"
func main(){
  fmt.Println("I'll be printed first")
  for i:=0;i<5;i++{
    defer fmt.Println(i)
  }
  fmt.Println("I'll be printed second")
}
