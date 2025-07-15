#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void printTriangle(const string& name, int a, int b, int c, int A, int B, int C) {
    cout << name << ":" << endl;
    cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
}

void printQuadrilateral(const string& name, int a, int b, int c, int d, int A, int B, int C, int D) {
    cout << name << ":" << endl;
    cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Треугольники
    printTriangle("Треугольник", 10, 20, 30, 50, 60, 70);

    printTriangle("Прямоугольный треугольник", 10, 20, 30, 50, 60, 90);

    printTriangle("Равнобедренный треугольник", 10, 20, 10, 50, 60, 50);

    printTriangle("Равносторонний треугольник", 30, 30, 30, 60, 60, 60);

    // Четырёхугольники
    printQuadrilateral("Четырёхугольник", 10, 20, 30, 40, 50, 60, 70, 80);

    printQuadrilateral("Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90);

    printQuadrilateral("Квадрат", 20, 20, 20, 20, 90, 90, 90, 90);

    printQuadrilateral("Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40);

    printQuadrilateral("Ромб", 30, 30, 30, 30, 30, 40, 30, 40);

    return 0;
}
