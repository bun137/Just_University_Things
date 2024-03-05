package main
import "fmt"
type Shape interface{
  area() float64
  peri() float64
}

type Rect struct{
  length float64
  bread float64
}

func (r Rect) area() float64{
  return r.length * r.bread
}

func (r Rect) peri() float64 {
    perii := 2 * (r.length + r.bread)
    return perii
}

func calculate(s Shape) {
    fmt.Println("Area:", s.area())
    fmt.Println("Perimeter:", s.peri())
}

func main() {
    rect := Rect{7, 4}
    calculate(rect)
}
