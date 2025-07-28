#include <iostream>
#include <memory>
#include <string>
#include <locale>

// Базовый класс для фигур
class Shape {
public:
    virtual void print_info() const = 0; // Чисто виртуальная функция для вывода информации
    virtual ~Shape() = default; // Виртуальный деструктор
};

// Класс для треугольников
class Triangle : public Shape {
protected:
    double a, b, c; // Стороны
    double A, B, C; // Углы

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
    }

    void print_info() const override {
        std::cout << "Треугольник:" << std::endl
            << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl
            << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
    }
};

// Класс для прямоугольных треугольников
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b)
        : Triangle(a, b, std::sqrt(a* a + b * b), 90.0, std::atan(b / a) * 180.0 / M_PI, std::atan(a / b) * 180.0 / M_PI) {
    }
};

// Класс для равнобедренных треугольников
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A)
        : Triangle(a, b, a, A, (180.0 - A) / 2.0, (180.0 - A) / 2.0) {
    }
};

// Класс для равносторонних треугольников
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
    }
};

// Класс для четырехугольников
class Quadrilateral : public Shape {
protected:
    double a, b, c, d; // Стороны
    double A, B, C, D; // Углы

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

    void print_info() const override {
        std::cout << "Четырехугольник:" << std::endl
            << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl
            << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
    }
};

// Класс для квадратов
class Square : public Quadrilateral {
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {
    }
};

// Класс для прямоугольников
class Rectangle : public Quadrilateral {
public:
    Rectangle(double width, double height)
        : Quadrilateral(width, height, width, height, 90, 90, 90, 90) {
    }
};

// Класс для параллелограммов
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
    }
};

// Класс для ромбов
class Rhombus : public Quadrilateral {
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {
    }
};

// Функция для вывода информации о фигурах
void print_shape_info(const Shape* shape) {
    shape->print_info();
}

int main() {
    // Устанавливаем локаль для корректной работы с русским языком
    std::locale::global(std::locale(""));

    // Создаем экземпляры фигур
    RightTriangle rightTriangle(3, 4);
    IsoscelesTriangle isoscelesTriangle(5, 5, 40);
    EquilateralTriangle equilateralTriangle(6);

    Rectangle rectangle(4, 2);
    Square square(3);
    Parallelogram parallelogram(5, 3, 60, 120);
    Rhombus rhombus(4, 60, 120);

    // Выводим информацию о фигурах
    print_shape_info(&rightTriangle);
    print_shape_info(&isoscelesTriangle);
    print_shape_info(&equilateralTriangle);

    print_shape_info(&rectangle);
    print_shape_info(&square);
    print_shape_info(&parallelogram);
    print_shape_info(&rhombus);

    return 0;
}