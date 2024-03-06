package main
import "math"
import "fmt"

type everything interface{
  area() float64
  peri() float64
}
type circle struct{
  radius float64
}

type rect struct{
  l float64
  b float64
}

func (r rect) area() float64{
  area := r.l * r.b
  return area
}

func (r rect) peri() float64{
  peri := 2 * (r.l+r.b)
  return peri
}

func (c circle) area() float64{
  return math.Pi * c.radius *c.radius
}

func (c circle) peri() float64{
  return 2* math.Pi * c.radius
}

func printfInfo(e everything){
  fmt.Println(e.area())
  fmt.Println(e.peri())
}

func main(){
  everything := []everything{
    circle{radius: 5},
    rect{l: 10, b: 5},
  }
  for _, e := range everything{
    printfInfo(e)
    fmt.Println("**********")
  }
}
