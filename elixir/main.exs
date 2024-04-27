defmodule Calculator do
  def main() do
    saludo()
  end

  defp saludo do
    IO.puts "Bienvenido usuario"
    IO.puts ""
    obtener()
  end

  defp obtener do
    name = IO.gets("Ingrese su nombre usuario: ") |> String.trim()

    years = IO.gets("Ingrese su edad " <> name <> ": ") |> String.trim() |> String.to_integer()

    IO.puts ""

    IO.puts "Su nombre es: " <> name
    IO.puts "Su edad es: #{years}"

    get(name)
  end

  defp get(name) do
    IO.puts ""
    IO.puts "1. Suma, 2. Resta, 3. Multiplicacion, 4. division"
    IO.puts ""

    op = IO.gets("¿Qué operación quiere realizar #{name}?: ") |> String.trim() |> String.to_integer()

    x = IO.gets("Ingrese un número para la operación que eligio #{name}: ") |> String.trim() |> String.to_integer()

    y = IO.gets("Ingrese un segundo número para la operación que eligio #{name}: ") |> String.trim() |> String.to_integer()

    cal(x, y, op, name)
  end

  defp cal(x, y, op, name) do
    IO.puts ""
    cond do
      op == 1 -> sum(x, y)
      op == 2 -> rest(x, y)
      op == 3 -> mul(x, y)
      op == 4 -> divi(x, y)
      true -> error(name)
    end
  end

  defp error(name) do
    IO.puts "Está operación no existe #{name}"
    get(name)
  end

  defp sum(x, y) do
    res = x + y
    IO.puts "La suma de #{x} y #{y} es #{res}"
  end

  defp rest(x, y) do
    res = x - y
    IO.puts "La resta de #{x} y #{y} es #{res}"
  end

  defp mul(x, y) do
    res = x * y
    IO.puts "La multiplicación de #{x} y #{y} es #{res}"
  end

  defp divi(x, y) do
    res = x / y
    IO.puts "La divición de #{x} y #{y} es #{res}"
  end
end

Calculator.main()
