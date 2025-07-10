
#include <iostream>
#include <string>

// Структура для хранения адреса
struct Address {
    std::string city;           // Название города
    std::string street;         // Название улицы
    int houseNumber;           // Номер дома
    int apartmentNumber;       // Номер квартиры
    std::string postalCode;    // Индекс
};

// Функция для вывода структуры на консоль
void printAddress(const Address& address) {
    std::cout << "=== Адрес ===" << std::endl;
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Дом: " << address.houseNumber << std::endl;
    std::cout << "Квартира: " << address.apartmentNumber << std::endl;
    std::cout << "Индекс: " << address.postalCode << std::endl;
    std::cout << "=============" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание экземпляров структуры
    Address address1 = {
        "Москва",
        "Тверская",
        10,
        25,
        "125009"
    };

    Address address2 = {
        "Санкт-Петербург",
        "Невский проспект",
        45,
        12,
        "191025"
    };

    Address address3;
    address3.city = "Казань";
    address3.street = "Баумана";
    address3.houseNumber = 58;
    address3.apartmentNumber = 7;
    address3.postalCode = "420111";

    // Тестирование функции
    std::cout << "Тестирование функции вывода адресов:" << std::endl;

    std::cout << "\nАдрес 1:" << std::endl;
    printAddress(address1);

    std::cout << "\nАдрес 2:" << std::endl;
    printAddress(address2);

    std::cout << "\nАдрес 3:" << std::endl;
    printAddress(address3);

    return 0;
}
