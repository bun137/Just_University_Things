package main

import "fmt"

type FAHRENHEIT float64

func main() {
    const freezingF FAHRENHEIT = 32
    const boilingF FAHRENHEIT = 212

    fmt.Printf("%g°F = %g°C\n", freezingF, fToc(freezingF)) 
    fmt.Printf("%g°F = %g°C\n", boilingF, fToc(boilingF)) 

}

func fToc(f FAHRENHEIT) FAHRENHEIT {
    return FAHRENHEIT (5) / FAHRENHEIT (9) * (f - 32)
    //return 5/9 * (f - 32)
}

