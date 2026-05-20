#include <iostream>
using namespace std;

class Estudiante {
private:
    string cedula;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float promedio;

public:

    Estudiante() {
        cedula = "";
        nombre = "";
        apellido = "";
        nota1 = 0;
        nota2 = 0;
        nota3 = 0;
        promedio = 0;
    }

    void setCedula(string c) {
        cedula = c;
    }

    void setNombre(string n) {
        nombre = n;
    }

    void setApellido(string a) {
        apellido = a;
    }

    void setNota1(float n1) {
        nota1 = n1;
    }

    void setNota2(float n2) {
        nota2 = n2;
    }

    void setNota3(float n3) {
        nota3 = n3;
    }

    string getCedula() {
        return cedula;
    }

    string getNombre() {
        return nombre;
    }

    string getApellido() {
        return apellido;
    }

    float getPromedio() {
        return promedio;
    }

    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3;
    }

    string determinarEstado() {
        if (promedio >= 7) {
            return "Aprobado";
        } else {
            return "Reprobado";
        }
    }

    void mostrarDatos() {
        cout << "\nCedula: " << cedula << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Estado: " << determinarEstado() << endl;
    }
};

int main() {

    Estudiante estudiantes[5];

    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < 5; i++) {

        string cedula, nombre, apellido;
        float n1, n2, n3;

        cout << "\nESTUDIANTE " << i + 1 << endl;

        cout << "Cedula: ";
        cin >> cedula;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Apellido: ";
        cin >> apellido;

        do {
            cout << "Nota 1: ";
            cin >> n1;
        } while (n1 < 0 || n1 > 10);

        do {
            cout << "Nota 2: ";
            cin >> n2;
        } while (n2 < 0 || n2 > 10);

        do {
            cout << "Nota 3: ";
            cin >> n3;
        } while (n3 < 0 || n3 > 10);

        estudiantes[i].setCedula(cedula);
        estudiantes[i].setNombre(nombre);
        estudiantes[i].setApellido(apellido);
        estudiantes[i].setNota1(n1);
        estudiantes[i].setNota2(n2);
        estudiantes[i].setNota3(n3);

        estudiantes[i].calcularPromedio();

        if (estudiantes[i].determinarEstado() == "Aprobado") {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    cout << "\nLISTADO DE ESTUDIANTES\n";

    for (int i = 0; i < 5; i++) {
        estudiantes[i].mostrarDatos();
    }

    cout << "\nTotal aprobados: " << aprobados << endl;
    cout << "Total reprobados: " << reprobados << endl;

    return 0;
}
