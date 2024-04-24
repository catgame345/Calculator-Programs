use std::io;

fn main() {
    welcome();

    get();
}

fn welcome() {
    println!("Bienvenido usuario");
}

fn get() {
    println!("ingrese su nombre usuario ");
    let mut name = String::new();
    io::stdin()
    .read_line(&mut name)
    .expect("Error");
    
    println!("Ingrese su edad {}", name);
    let mut ed = String::new();
    io::stdin()
    .read_line(&mut ed)
    .expect("Error");
    
    let _edad: i32 = ed.trim().parse()
    .expect("Por favor ingrese un numero valido!");

    println!("Ingrese que operacion quiere hacer {}", name);
    println!("1. Suma, 2. Resta, 3. Multiplicacion, 4. division");

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("Error");

    let number: i32 = inp.trim().parse().expect("Ingrese un numero valido");

    println!("Ingrese un numero para la operacion que eligio {}", name);
    let mut num1s = String::new();
    io::stdin().read_line(&mut num1s).expect("Error");

    let num1: i32 = num1s.trim().parse().expect("Por favor ingrese un numero valido!");

    println!("Ingrese un segundo numer para la operacion que eligio {}", name);
    let mut num2s = String::new();
    io::stdin().read_line(&mut num2s).expect("Error");

    let num2: i32 = num2s.trim().parse().expect("Por favor ingrese un numero valido!");

    comparate(number, num1, num2);
}

fn comparate(number: i32, x: i32, y: i32) {
    match number {
        1 => sum(x, y),
        2 => res(x, y),
        3 => mul(x, y),
        4 => div(x, y),
        _ => println!("Esta operacion no existe"),
    }
}

fn sum(x: i32, y: i32) {
    let resu = x + y;
    println!("La suma de {} y {} es {}", x, y, resu)
}

fn res(x: i32, y: i32) {
    let resu: i32 = x - y;
    println!("La resta de {} y {} es {}", x, y, resu)
}

fn mul(x: i32, y: i32) {
    let resu: i32 = x * y;
    println!("La multiplicacion de {} y {} es {}", x, y, resu)
}

fn div(x: i32, y: i32) {
    let resu: i32 = x / y;
    println!("La division de {} y {} es {}", x, y, resu)
}
