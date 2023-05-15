#include "Chat.h"

Chat::Chat() : currentUser_(nullptr) {}

Chat::~Chat() {
    // ������� ������ ��� �������� User � ���������� users_
    for (auto& pair : users_) {
        delete pair.second;
    }
}

void Chat::registerUser() {
    std::string name, password;
    std::cout << "������� ��� ������������: ";
    std::cin >> name;
    std::cout << "������� ������: ";
    std::cin >> password;

    User* user = new User(name, password);
    users_[name] = user;
    std::cout << "������������ " << name << " ������� ���������������." << std::endl;
}

void Chat::sendGroupMessage(const std::string& message) {
    Message groupMessage(currentUser_, message);
    for (auto& pair : messages) {
        pair.second.push_back(groupMessage);
    }
    std::cout << "����� ��������� ����������: " << message << std::endl;
}

void Chat::sendUserMessage(User* sender, const std::string& recipient, const std::string& message) {
    User* recipientUser = users_[recipient];
    if (recipientUser) {
        Message userMessage(sender, message);
        messages[recipient].push_back(userMessage);
        std::cout << "��������� ��� " << recipient << " ����������: " << message << std::endl;
    }
    else {
        std::cout << "������������ " << recipient << " �� ������." << std::endl;
    }
}

void Chat::viewMessages() {
    std::string username;
    std::cout << "������� ��� ������������ ��� ��������� ���������: ";
    std::cin >> username;

    auto it = messages.find(username);
    if (it != messages.end()) {
        std::cout << "��������� ��� ������������ " << username << ":" << std::endl;
        for (const Message& message : it->second) {
            std::cout << "- �����������: " << message.getSender()->getName() << std::endl;
            std::cout << "  ����� ���������: " << message.getText() << std::endl;
        }
    }
    else {
        std::cout << "������������ " << username << " �� ����� ���������." << std::endl;
    }
}

void Chat::viewUsers() {
    std::cout << "������������������ ������������:" << std::endl;
    for (const auto& pair : users_) {
        std::cout << "- " << pair.first << std::endl;
    }
}

void Chat::loginUser() {
    std::string login, password;
    std::cout << "������� �����: ";
    std::cin >> login;
    std::cout << "������� ������: ";
    std::cin >> password;

    auto it = users_.find(login);
    if (it != users_.end() && it->second->getPassword() == password) {
        std::cout << "�� ������� ����� � ���!" << std::endl;
        std::cout << std::endl;
        std::cout << "������������, " << it->second->getName() << "." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        currentUser_ = it->second;

        while (true) {
            std::cout << "�������� ��������:" << std::endl << std::endl;
            std::cout << "1. ��������� ���������" << std::endl;
            std::cout << "2. ��������� ���������" << std::endl;
            std::cout << "3. ����������� ������������������ �������������" << std::endl;
            std::cout << "4. ����� �� ����" << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;

            int choice;
            std::cin >> choice;
            std::cout << "---------------------" << std::endl << std::endl;

            if (choice == 1) {
                std::string recipient, message;
                std::cout << "������� ��� ����������: ";
                std::cin >> recipient;
                std::cout << "������� ����� ���������: ";
                std::cin.ignore(); // ������� ������ ����� ����� �������������� std::getline()
                std::getline(std::cin, message);
                sendUserMessage(currentUser_, recipient, message);
            }
            else if (choice == 2) {
                viewMessages();
            }
            else if (choice == 3) {
                viewUsers();
            }
            else if (choice == 4) {
                break;
            }
            else {
                std::cout << "������������ �����. ���������� �����." << std::endl;
            }
        }
    }
    else {
        std::cout << "������������ � ����� ������� � ������� �� ������." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << "�������� �����: " << std::endl << std::endl;
    }
}
