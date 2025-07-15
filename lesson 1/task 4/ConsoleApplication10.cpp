#include <iostream>
#include <string>

// Базовый класс Figure
class Figure {
private:
    int sides_count;

protected:
    std::string name;

    // Защищённый конструктор с параметрами для наследников
    Figure(int sides, const std::string& figure_name)
        : sides_count(sides), name(figure_name) {
    }

public:
    // Публичный конструктор без параметров
    Figure() : sides_count(0), name("Фигура") {}

    // Виртуальный деструктор
    virtual ~Figure() = default;

    // Публичный метод для получения количества сторон
    int get_sides_count() const {
        return sides_count;
    }

    // Публичный метод для получения названия фигуры
    std::string get_name() const {
        return name;
    }
};

// Класс Triangle наследует Figure
class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

// Класс Quadrangle наследует Figure
class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

// Главная функция - демонстрация работы
int main() {
    setlocale(LC_ALL, "Russian");
    // Создание экземпляров каждого класса
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    // Вывод информации о каждой фигуре
    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}
