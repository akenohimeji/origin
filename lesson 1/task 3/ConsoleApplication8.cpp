#include <iostream>
#include <fstream>
#include <string>
#include <locale>

class address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    // Конструктор с параметрами - нельзя создать пустой адрес
    address(const std::string& city, const std::string& street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {
    }

    // Метод для получения строки для вывода в файл
    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::locale::global(std::locale(""));

    // Выводим текущую директорию для отладки
    std::cout << "Попытка открыть файл in.txt..." << std::endl;

    std::ifstream inFile("in.txt");
    // Устанавливаем локаль для входного файла
    inFile.imbue(std::locale(""));

    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла in.txt" << std::endl;
        std::cerr << "Убедитесь, что файл существует в текущей директории" << std::endl;
        return 1;
    }

    std::cout << "Файл in.txt успешно открыт!" << std::endl;

    std::ofstream outFile("out.txt");
    // Устанавливаем локаль для выходного файла
    outFile.imbue(std::locale(""));

    if (!outFile.is_open()) {
        std::cerr << "Ошибка создания файла out.txt" << std::endl;
        inFile.close();
        return 1;
    }

    std::cout << "Файл out.txt успешно создан!" << std::endl;

    int n;
    inFile >> n;
    inFile.ignore(); // игнорируем символ новой строки после числа

    std::cout << "Количество адресов: " << n << std::endl;

    // Создаем динамический массив указателей на объекты address
    address** addresses = new address * [n];

    // Считываем адреса с помощью цикла for
    for (int i = 0; i < n; i++) {
        std::string city, street;
        int house, apartment;

        std::getline(inFile, city);
        std::getline(inFile, street);
        inFile >> house;
        inFile >> apartment;
        inFile.ignore(); // игнорируем символ новой строки после числа

        std::cout << "Считан адрес " << (i + 1) << ": " << city << ", " << street << ", " << house << ", " << apartment << std::endl;

        // Создаем объект address с помощью конструктора с параметрами
        addresses[i] = new address(city, street, house, apartment);
    }

    // Выводим количество адресов
    outFile << n << std::endl;

    // Выводим адреса в обратном порядке
    for (int i = n - 1; i >= 0; i--) {
        outFile << addresses[i]->get_output_address() << std::endl;
    }

    // Освобождаем память
    for (int i = 0; i < n; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    inFile.close();
    outFile.close();

    std::cout << "Программа успешно выполнена!" << std::endl;

    return 0;
}
