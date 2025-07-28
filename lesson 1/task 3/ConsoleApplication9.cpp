#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <locale>

class Address {
public:
    Address(const std::string& city, const std::string& street, const std::string& house, const std::string& apartment)
        : city(city), street(street), house(house), apartment(apartment) {
    }

    std::string getCity() const { return city; }
    std::string getStreet() const { return street; }
    std::string getHouse() const { return house; }
    std::string getApartment() const { return apartment; }

private:
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;
};

class AddressManager {
public:
    void readAddresses(const std::string& filename);
    void sortAddresses();
    void writeAddresses(const std::string& filename) const;

private:
    std::vector<Address> addresses;
};

void AddressManager::readAddresses(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Ошибка: не удалось открыть файл " + filename);
    }

    int n;
    inputFile >> n;
    inputFile.ignore(); // Игнорируем символ новой строки после числа

    for (int i = 0; i < n; i++) {
        std::string city, street, house, apartment;
        std::getline(inputFile, city);
        std::getline(inputFile, street);
        std::getline(inputFile, house);
        std::getline(inputFile, apartment);
        addresses.emplace_back(city, street, house, apartment);
    }

    inputFile.close();
}

void AddressManager::sortAddresses() {
    std::sort(addresses.begin(), addresses.end(), [](const Address& a, const Address& b) {
        return a.getCity() < b.getCity(); // Сортируем по названию города
        });
}

void AddressManager::writeAddresses(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Ошибка: не удалось создать файл " + filename);
    }

    outputFile << addresses.size() << std::endl; // Записываем количество адресов

    for (const auto& addr : addresses) {
        outputFile << addr.getCity() << ", " << addr.getStreet() << ", "
            << addr.getHouse() << ", " << addr.getApartment() << std::endl;
    }

    outputFile.close();
}

int main() {
    // Устанавливаем локаль для корректной работы с русским языком
    std::locale::global(std::locale(""));

    try {
        AddressManager manager;
        manager.readAddresses("in.txt");
        manager.sortAddresses();
        manager.writeAddresses("out.txt");

        std::cout << "Программа успешно выполнена. Результат записан в файл out.txt" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}