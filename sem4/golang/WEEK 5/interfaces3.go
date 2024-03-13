package main

import "fmt"

// Define an interface for vehicles
type Vehicle interface {
	Start()
	Stop()
}

// Define a struct type for a car
type Car struct {
	Brand string
}

// Implement Start method for a car
func (c Car) Start() {
	fmt.Printf("%s car has started.\n", c.Brand)
}

// Implement Stop method for a car
func (c Car) Stop() {
	fmt.Printf("%s car has stopped.\n", c.Brand)
}

// Define a struct type for a motorcycle
type Motorcycle struct {
	Brand string
}

// Implement Start method for a motorcycle
func (m Motorcycle) Start() {
	fmt.Printf("%s motorcycle has started.\n", m.Brand)
}

// Implement Stop method for a motorcycle
func (m Motorcycle) Stop() {
	fmt.Printf("%s motorcycle has stopped.\n", m.Brand)
}

func main() {
	// Create instances of a car and a motorcycle
	car := Car{Brand: "TATA"}
	motorcycle := Motorcycle{Brand: "KTM"}

	// Use the Vehicle interface to start and stop the car and motorcycle
	driveVehicle(car)
	driveVehicle(motorcycle)
}

// Function to demonstrate how the Vehicle interface can be used
func driveVehicle(v Vehicle) {
	v.Start()
	v.Stop()
}
