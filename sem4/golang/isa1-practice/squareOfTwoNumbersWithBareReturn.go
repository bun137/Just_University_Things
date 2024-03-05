
package main
import("fmt"
        "math")
func main(){
  fmt.Println(squaree(2,3))
}
func squaree(x float64 ,y float64) (firstSquare float64, secondSquare float64){
  firstSquare = math.Pow(float64(x),2)
  secondSquare = math.Pow(float64(y),2)
  return
}
