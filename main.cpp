#include <iostream>
#include "Chat.h"
#include <windows.h>

int main() {
    // ������� �����������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_Ru");

    Chat chat;

    std::cout << " ������ SkillFactory." << std::endl;
    std::cout << " ����������� ����, ������." << std::endl;
    std::cout << " �� �������� � ����� ����." << std::endl;
    std::cout << " version 2.5\n " << std::endl;

    while (true) {
        std::cout << "   1: [���� ������������� ������������] \n"
            << "   2: [����������� ������ ������������] \n"
            << "   0: [�������]\n" << std::endl;

        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << " �������� �����: ";

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
            std::cout << "\n   ���������� ������...  " << '\n';
            std::cout << "--------------" << std::endl << std::endl;
            return 0;

        default:
            std::cout << "\n [ �������� �����. ���������� �����. ]" << std::endl;
            std::cout << "--------------------------------------------------" << std::endl << std::endl;
            break;
        }
    }

    return 0;
}
