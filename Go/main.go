package main

import "fmt"

type User struct {
	Name string
	Years int
}

func main() {
	saludo()
	obtener()
}

func saludo() {
	fmt.Println("Bienvenido usuario")
}

func obtener() {
	var name string
	var years int

	fmt.Println("Ingrese su nombre usuario: ")
	fmt.Scanln(&name)

	fmt.Println("Ingrese su edad " + name + ": ")
	fmt.Scanln(&years)

	user := User {
		Name: name,
		Years: years,
	}

	fmt.Println("Su nombre es:", user.Name)
	fmt.Println("Tiene:", user.Years, "años")

	get(user.Name)
}

func get(name string) {
	var res int
	var x int
	var y int

	fmt.Println("1. Suma, 2. Resta, 3. Multiplicacion, 4. division")
	fmt.Println("¿Qué operación quiere realizar", name, "?: ")
	fmt.Scanln(&res)
	fmt.Println("Ingrese un número para la operación que eligio", name, ": ")
	fmt.Scanln(&x)
	fmt.Println("Ingrese un segundo número para la operación que eligio", name, ": ")
	fmt.Scanln(&y)

	cal(res, x, y, name)
}

func cal(res int, x int, y int, name string) {
	if res == 1 {
		sum(x, y, name)
	} else if res == 2 {
		rest(x, y, name)
	} else if res == 3 {
		mul(x, y, name)
	} else {
		div(x, y, name)
	}
}

func sum(x int, y int, name string) {
	res := x + y
	fmt.Println("La suma de", x, "y", y, "es", res, ",", name)
}

func rest(x int, y int, name string) {
	res := x - y
	fmt.Println("La resta de", x, "y", y, "es", res, ",", name)
}

func mul(x int, y int, name string) {
	res := x * y
	fmt.Println("La multiplicación de", x, "y", y, "es", res, ",", name)
}

func div(x int, y int, name string) {
	res := x / y
	fmt.Println("La división de", x, "y", y, "es", res, ",", name)
}