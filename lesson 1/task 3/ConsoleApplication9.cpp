#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <locale>

struct Address {
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;
};

int main() {
    // Устанавливаем локаль для корректной работы с русским языком
    std::locale::global(std::locale(""));

    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл in.txt" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл out.txt" << std::endl;
        return 1;
    }

    int n;
    inputFile >> n;
    inputFile.ignore(); // Игнорируем символ новой строки после числа

    std::vector<Address> addresses(n);

    // Читаем адреса из файла
    for (int i = 0; i < n; i++) {
        std::getline(inputFile, addresses[i].city);
        std::getline(inputFile, addresses[i].street);
        std::getline(inputFile, addresses[i].house);
        std::getline(inputFile, addresses[i].apartment);
    }

    // Сортируем адреса по названию города в алфавитном порядке
    std::sort(addresses.begin(), addresses.end(), [](const Address& a, const Address& b) {
        return a.city < b.city;
        });

    // Записываем количество адресов в выходной файл
    outputFile << n << std::endl;

    // Записываем отсортированные адреса в новом формате
    for (const auto& addr : addresses) {
        outputFile << addr.city << ", " << addr.street << ", "
            << addr.house << ", " << addr.apartment << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Программа успешно выполнена. Результат записан в файл out.txt" << std::endl;

    return 0;
}
