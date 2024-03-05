package main
import("fmt"
        "math")
func main(){
  fmt.Println(squaree(2,3))
}
func squaree(x float64 ,y float64) (float64,float64){
  return math.Pow(float64(x),2),math.Pow(float64(y),2)
}
