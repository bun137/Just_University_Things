package main

import "fmt"

func main() {
    const freezingF = 32.0
    const boilingF = 212.0

    fmt.Printf("%g°F = %g°C\n", freezingF, fToc(freezingF)) 
    fmt.Printf("%g°F = %g°C\n", boilingF, fToc(boilingF)) 

}

func fToc(f float64) float64 {
    return 5/9 * (f - 32)
    //return 5.0/9.0 * (f - 32)
}

