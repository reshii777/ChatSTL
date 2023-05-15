#include <iostream>
#include "Chat.h"
#include <windows.h>

int main() {
    // русская локализация
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_Ru");

    Chat chat;

    std::cout << " Проект SkillFactory." << std::endl;
    std::cout << " Приветствую тебя, Джедай." << std::endl;
    std::cout << " Да пребудет с тобой сила." << std::endl;
    std::cout << " version 2.5\n " << std::endl;

    while (true) {
        std::cout << "   1: [Вход существующего пользователя] \n"
            << "   2: [Регистрация нового пользователя] \n"
            << "   0: [Закрыть]\n" << std::endl;

        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << " Выберите пункт: ";

        int choice;
        std::cin >> choice;
        std::cout << "---------------------\n" << std::endl;

        switch (choice) {
        case 1:
            chat.loginUser();
            break;

        case 2:
            chat.registerUser();
            break;

        case 0:
            std::cout << "\n   Завершение работы...  " << '\n';
            std::cout << "--------------" << std::endl << std::endl;
            return 0;

        default:
            std::cout << "\n [ Неверный выбор. Попробуйте снова. ]" << std::endl;
            std::cout << "--------------------------------------------------" << std::endl << std::endl;
            break;
        }
    }

    return 0;
}
