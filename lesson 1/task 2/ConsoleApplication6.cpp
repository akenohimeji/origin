#include <iostream>
#include <locale>
#include <string>

class Counter {
private:
    int value;  

public:

    Counter() : value(1) {}

    Counter(int initial_value) : value(initial_value) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Counter counter;
    std::string choice;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";

    std::cin >> choice;

    if (choice == "да" || choice == "Да" || choice == "ДА") {
        int initial_value;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial_value;
        counter = Counter(initial_value);  
    }
    else {
        counter = Counter();  
    }

    char command;
    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();  
            break;

        case '-':
            counter.decrement();  
            break;

        case '=':
            std::cout << counter.getValue() << std::endl;  
            break;

        case 'x':
            std::cout << "До свидания!" << std::endl;
            return 0;

        default:
            break;
        }
    }

    return 0;
}
