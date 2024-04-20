#include <iostream>
#include <tuple>
#include <stdlib.h>

using namespace std;

class Calculator {
    private:
    int edad;
    string nombre;

    public:
    Calculator(int, string); //constructor
    int sum(int, int);
    int res(int, int, bool);
    int mul(int,int);
    int div(int, int, bool);
    void init();
    void setUser(int, string);
    tuple<int, string> change();
    void get();
    ~Calculator(); //destructor
};

Calculator::Calculator(int _edad, string _nombre) { //constructor
    edad = _edad;
    nombre = _nombre;
}

Calculator::~Calculator() { //destructor

}

int Calculator::sum(int x, int y) {
    int res = x + y;
    return res;
}

int Calculator::res(int x, int y, bool yes) {
    int res;

    if (yes) {
        res = x - y;
    } else {
        if (x >= y) {
            res = x - y;
        } else {
            res = y - x;
        }
    }

    return res;
}

int Calculator::mul(int x, int y) {
    int res = x * y;
    return res;
}

int Calculator::div(int x, int y, bool yes) {
    int res;

    if (yes) {
        res = x / y;
    } else {
        if (x >= y) {
            res = x / y;
        } else {
            res = y / x;
        }
    }

    return res;
}

void Calculator::get() {
    int resp;

    cout << "Que operacion quiere hacer " << nombre << "?: " << endl;
    int operacion;
    cout << endl;
    cout << "1. Suma, 2. Resta, 3. Multiplicacion, 4. division" << endl;
    cout << endl;
    cin >> operacion;
    cout << "Ingrese un primer numero para la operacion " << nombre << ": " << endl;
    int n1;
    cin >> n1;
    cout << "Ingrese un segundo numero para la operacion " << nombre << ": " << endl;
    int n2;
    cin >> n2;
    if (operacion == 1) {
        resp = sum(n1, n2);
    } else if(operacion == 2) {
        cout << "Quiere numeros negativos " << nombre << "?: " << endl;
        string negative;
        cin >> negative;
        if (negative == "si") {
            resp = res(n1, n2, true);
        } else {
            resp = res(n1, n2, false);
        }
    } else if (operacion == 3) {
        resp = mul(n1, n2);
    } else if (operacion == 4) {
        cout << "Quieres numeros decimales " << nombre << "?: " << endl;
        string decimal;
        cin >> decimal;
        if (decimal == "si") {
            resp = div(n1, n2, true);
        } else {
            resp = div(n1, n2, false);
        }
    }
    cout << "El resultado de la operacion es: " << resp << endl;
}

void Calculator::setUser(int _edad, string _nombre) {
    edad = _edad;
    nombre = _nombre;
}

tuple<int, string> Calculator::change() {
    cout << "Ingrese su nombre usuario: " << endl;
    string name;
    cin >> name;
    cout << "Ingrese su edad " << name << ": " << endl;
    int years;
    cin >> years;
    return make_tuple(years, name);
}

void Calculator::init() {
    string years;

    if (edad == 1) {
        years = "anio";
    } else {
        years = "anios";
    }

    cout << "Hola " << nombre << "!" << ". Tienes " << edad << " " << years << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Bienvenido usuario" << endl;
    cout << endl;
    cout << "Ingrese su nombre usuario: " << endl;
    string name;
    cin >> name;
    cout << "Ingrese su edad " << name << ": " << endl;
    int years;
    cin >> years;
    Calculator user(years, name);

    cout << "Quiere cambiar el nombre y la edad " << name << "?: " << endl;
    string resp;
    cin >> resp;
    if (resp == "si") {
        auto changes = user.change();
        
        int edad = get<0>(changes);
        string nombre = get<1>(changes);

        user.setUser(edad, nombre);
    }

    user.init();

    user.get();

    user.~Calculator();

    system("pause");
    return 0;
}
