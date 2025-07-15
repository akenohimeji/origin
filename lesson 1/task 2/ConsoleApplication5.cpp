#include <iostream>
#include <locale>

class Calculator {
private:
    double num1;
    double num2;

    // Методы для арифметических операций
    double add() {
        return num1 + num2;
    }
 public:
    double multiply() {
        return num1 * num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {
        return num2 - num1;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {
        return num2 / num1;
    }

    // Методы для установки значений с использованием this и условного оператора
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            return false;
        }
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    // Настройка локали для отображения русского языка
    setlocale(LC_ALL, "Russian");

    // Создание экземпляра класса Calculator
    Calculator calc;

    while (true) {
        double num1, num2;

        // Ввод первого числа
        std::cout << "Введите num1: ";
        std::cin >> num1;

        // Проверка и установка первого числа
        while (!calc.set_num1(num1)) {
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num1: ";
            std::cin >> num1;
        }

        // Ввод второго числа
        std::cout << "Введите num2: ";
        std::cin >> num2;

        // Проверка и установка второго числа
        while (!calc.set_num2(num2)) {
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num2: ";
            std::cin >> num2;
        }

        // Вывод результатов операций
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}
