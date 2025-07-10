#include <iostream>
#include <string>
#include <iomanip>

// Структура для хранения информации о банковском счёте
struct BankAccount {
    int accountNumber;      // Номер счёта
    std::string ownerName;  // Имя владельца
    double balance;         // Количество денег на счету
};

// Функция для изменения баланса счёта
void updateBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    setlocale(LC_ALL, "Russian");
    BankAccount account;

    // Ввод данных пользователем
    std::cout << "Введите номер счёта: ";
    std::cin >> account.accountNumber;

    std::cout << "Введите имя владельца: ";
    std::cin.ignore();
    std::getline(std::cin, account.ownerName);

    std::cout << "Введите баланс счёта: ";
    std::cin >> account.balance;

    // Ввод нового баланса
    double newBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    // Обновление баланса
    updateBalance(account, newBalance);

    // Вывод обновлённой информации
    std::cout << "\n=== Обновлённая информация о счёте ===" << std::endl;
    std::cout << "Номер счёта: " << account.accountNumber << std::endl;
    std::cout << "Владелец: " << account.ownerName << std::endl;
    std::cout << "Баланс: " << std::fixed << std::setprecision(2)
        << account.balance << " руб." << std::endl;

    return 0;
}
