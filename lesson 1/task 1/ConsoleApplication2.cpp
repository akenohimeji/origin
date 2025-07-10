#include <iostream>
#include <string>
#include <map>






// Перечисление для месяцев
enum Month {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

// Функция для получения названия месяца
std::string getMonthName(Month month) {
    static std::map<Month, std::string> monthNames = {
        {JANUARY, "Январь"},
        {FEBRUARY, "Февраль"},
        {MARCH, "Март"},
        {APRIL, "Апрель"},
        {MAY, "Май"},
        {JUNE, "Июнь"},
        {JULY, "Июль"},
        {AUGUST, "Август"},
        {SEPTEMBER, "Сентябрь"},
        {OCTOBER, "Октябрь"},
        {NOVEMBER, "Ноябрь"},
        {DECEMBER, "Декабрь"}
    };

    return monthNames[month];
}

// Функция для проверки корректности номера месяца
bool isValidMonth(int monthNumber) {
    return monthNumber >= 1 && monthNumber <= 12;
}

int main() {
    int monthNumber;
    setlocale(LC_ALL, "Russian");

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;

        // Проверяем на ошибку ввода
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        if (monthNumber == 0) {
            std::cout << "До свидания" << std::endl;
            break;
        }

        if (isValidMonth(monthNumber)) {
            Month month = static_cast<Month>(monthNumber);
            std::cout << getMonthName(month) << std::endl;
        }
        else {
            std::cout << "Неправильный номер!" << std::endl;
        }

    } while (monthNumber != 0);

    return 0;
}
