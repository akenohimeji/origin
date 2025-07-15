#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

class Figure {
protected:
    string name;
    int sides;
public:
    Figure(string n = "Фигура", int s = 0) : name(n), sides(s) {}
    virtual ~Figure() = default;

    virtual void print_info() const {
        cout << name << ":\nПравильная: " << (check() ? "да" : "нет") << "\nКоличество сторон: " << sides << endl;
    }
    virtual bool check() const { return sides == 0; }
};

class Triangle : public Figure {
protected:
    double a, b, c, A, B, C;
public:
    Triangle(string n, double a, double b, double c, double A, double B, double C)
        : Figure(n, 3), a(a), b(b), c(c), A(A), B(B), C(C) {
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << endl;
    }
    bool check() const override { return sides == 3 && abs(A + B + C - 180) < 0.1; }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle("Прямоугольный треугольник", a, b, c, A, B, 90) {
    }
    bool check() const override { return Triangle::check() && abs(C - 90) < 0.1; }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C)
        : Triangle("Равнобедренный треугольник", a, b, c, A, B, C) {
    }
    bool check() const override { return Triangle::check() && abs(a - c) < 0.1 && abs(A - C) < 0.1; }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double s) : Triangle("Равносторонний треугольник", s, s, s, 60, 60, 60) {}
    bool check() const override { return Triangle::check() && abs(a - b) < 0.1 && abs(A - 60) < 0.1; }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d, A, B, C, D;
public:
    Quadrilateral(string n, double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure(n, 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool check() const override { return sides == 4 && abs(A + B + C + D - 360) < 0.1; }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b) : Quadrilateral("Прямоугольник", a, b, a, b, 90, 90, 90, 90) {}
    bool check() const override { return Quadrilateral::check() && abs(a - c) < 0.1 && abs(b - d) < 0.1 && abs(A - 90) < 0.1; }
};

class Square : public Quadrilateral {
public:
    Square(double s) : Quadrilateral("Квадрат", s, s, s, s, 90, 90, 90, 90) {}
    bool check() const override { return Quadrilateral::check() && abs(a - b) < 0.1 && abs(A - 90) < 0.1; }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B) : Quadrilateral("Параллелограмм", a, b, a, b, A, B, A, B) {}
    bool check() const override { return Quadrilateral::check() && abs(a - c) < 0.1 && abs(A - C) < 0.1; }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double s, double A, double B) : Quadrilateral("Ромб", s, s, s, s, A, B, A, B) {}
    bool check() const override { return Quadrilateral::check() && abs(a - b) < 0.1 && abs(A - C) < 0.1; }
};

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    Figure f; f.print_info(); cout << endl;
    Triangle t("Треугольник", 10, 20, 30, 50, 60, 70); t.print_info(); cout << endl;
    RightTriangle rt(10, 20, 30, 50, 40); rt.print_info(); cout << endl;
    IsoscelesTriangle it(10, 20, 10, 50, 80, 50); it.print_info(); cout << endl;
    EquilateralTriangle et(30); et.print_info(); cout << endl;
    Quadrilateral q("Четырёхугольник", 10, 20, 30, 40, 50, 60, 70, 180); q.print_info(); cout << endl;
    Rectangle r(10, 20); r.print_info(); cout << endl;
    Square s(20); s.print_info(); cout << endl;
    Parallelogram p(20, 30, 30, 150); p.print_info(); cout << endl;
    Rhombus rh(30, 30, 150); rh.print_info(); cout << endl;

    return 0;
}
