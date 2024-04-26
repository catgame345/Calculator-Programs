using System;

class Calculator
{
    private string Name { get; set; }
    private int Years { get; set; }

    public Calculator(string name, int years)
    {
        Name = name ?? throw new ArgumentNullException(nameof(name));
        Years = years;
    }

    public void Inicio()
    {
        string anio = Years == 1 ? "año" : "años";
        Console.WriteLine($"Su nombre es {Name} y tiene {Years} {anio}.");
        Get();
    }

    private void Get()
    {
        Console.WriteLine("1. Suma, 2. Resta, 3. Multiplicacion, 4. division");
        Console.WriteLine($"Ingresa que operacion quiere realizar {Name}: ");
        int opera = int.Parse(Console.ReadLine());
        Console.WriteLine($"Ingrese un numero para la operacion {Name}: ");
        int x = int.Parse(Console.ReadLine());
        Console.WriteLine($"Ingrese un segundo numero para la operacion {Name}: ");
        int y = int.Parse(Console.ReadLine());

        Comparar(x, y, opera);
    }

    private void Comparar(int x, int y, int opera)
    {
        if (opera == 1)
        {
            Sum(x, y);
        } else if (opera == 2)
        {
            Res(x, y);
        } else if (opera == 3)
        {
            Mul(x, y);
        } else
        {
            Div(x, y);
        }
    }

    private void Sum(int x, int y)
    {
        int res = x + y;
        Console.WriteLine($"La suma de {x} y {y} es {res}");
    }

    private void Res(int x, int y)
    {
        int res = x - y;
        Console.WriteLine($"La resta de {x} y {y} es {res}");
    }

    private void Mul(int x, int y)
    {
        int res = x * y;
        Console.WriteLine($"La multiplicación de {x} y {y} es {res}");
    }

    private void Div(int x, int y)
    {
        int res = x / y;
        Console.WriteLine($"La división de {x} y {y} es {res}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Saludar();

        Obtener();
    }

    static void Saludar()
    {
        Console.WriteLine("Bienvenido usuario");
    }

    static void Obtener()
    {
        Console.WriteLine("Ingrese su nombre usuario: ");
        string name = Console.ReadLine() ?? "";
        Console.WriteLine($"Ingrese su edad {name}: ");
        int years = int.Parse(Console.ReadLine());

        Usuario(name, years);
    }

    static void Usuario(string name, int years)
    {
        Calculator user = new Calculator(name, years);

        user.Inicio();
    }
}
