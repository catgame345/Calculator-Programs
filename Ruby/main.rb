class Calculator
  def main
    saludo
  end

  def saludo
    puts "Bienvenido usuario"
    puts ""
    obtener
  end

  def obtener
    puts "Ingrese su nombre usuario: "
    @name = gets.chomp
    puts "Ingrese su edad " + @name + ": "
    @years = gets.chomp.to_i
    puts ""
    puts "Nombre: " + @name
    puts "Edad: " + @years.to_s

    get
  end

  def get
    puts ""
    puts "1. Suma, 2. Resta, 3. Multiplicacion, 4. division"
    puts ""

    puts "¿Que operacion quiere realizar " + @name + "?: "
    @op = gets.chomp.to_i
    puts "Ingrese un numero para la operacion que eligio " + @name + ": "
    @x = gets.chomp.to_i
    puts "Ingrese un segundo numero para la operacion que eligio " + @name + ": "
    @y = gets.chomp.to_i

    cal
  end

  def cal
    puts ""
    if @op == 1
      sum
    elsif @op == 2
      rest
    elsif @op == 3
      mul
    elsif @op == 4
      divi
    end
  end

  def sum
    res = @x + @y
    puts "La suma de "+ @x.to_s + " y "+ @y.to_s + " es " + res.to_s
  end

  def rest
    res = @x - @y
    puts "La resta de "+ @x.to_s + " y "+ @y.to_s + " es " + res.to_s
  end

  def mul
    res = @x * @y
    puts "La multiplicacion de "+ @x.to_s + " y "+ @y.to_s + " es " + res.to_s
  end

  def divi
    res = @x / @y
    puts "La division de "+ @x.to_s + " y "+ @y.to_s + " es " + res.to_s
  end
end

calculator = Calculator.new
calculator.main
