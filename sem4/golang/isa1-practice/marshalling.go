
package main

import (
    "encoding/json"
    "fmt"
)

type Person struct {
    Name     string
    Age      int
    IsStudent bool
    Courses []string
}

func main() {
    p := Person{
        Name: "John Doe",
        Age: 30,
        IsStudent: false,
        Courses: []string{"math", "history", "chemistry"},
    }

    jsonData, err := json.Marshal(p)
    if err != nil {
        fmt.Println("Error:", err)
        return
    }

    fmt.Println(string(jsonData))
}
