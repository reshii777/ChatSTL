#include "Chat.h"

Chat::Chat() : currentUser_(nullptr) {}

Chat::~Chat() {
    // Очистка памяти для объектов User в контейнере users_
    for (auto& pair : users_) {
        delete pair.second;
    }
}

void Chat::registerUser() {
    std::string name, password;
    std::cout << "Введите имя пользователя: ";
    std::cin >> name;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    User* user = new User(name, password);
    users_[name] = user;
    std::cout << "Пользователь " << name << " успешно зарегистрирован." << std::endl;
}

void Chat::sendGroupMessage(const std::string& message) {
    Message groupMessage(currentUser_, message);
    for (auto& pair : messages) {
        pair.second.push_back(groupMessage);
    }
    std::cout << "Общее сообщение отправлено: " << message << std::endl;
}

void Chat::sendUserMessage(User* sender, const std::string& recipient, const std::string& message) {
    User* recipientUser = users_[recipient];
    if (recipientUser) {
        Message userMessage(sender, message);
        messages[recipient].push_back(userMessage);
        std::cout << "Сообщение для " << recipient << " отправлено: " << message << std::endl;
    }
    else {
        std::cout << "Пользователь " << recipient << " не найден." << std::endl;
    }
}

void Chat::viewMessages() {
    std::string username;
    std::cout << "Введите имя пользователя для просмотра сообщений: ";
    std::cin >> username;

    auto it = messages.find(username);
    if (it != messages.end()) {
        std::cout << "Сообщения для пользователя " << username << ":" << std::endl;
        for (const Message& message : it->second) {
            std::cout << "- Отправитель: " << message.getSender()->getName() << std::endl;
            std::cout << "  Текст сообщения: " << message.getText() << std::endl;
        }
    }
    else {
        std::cout << "Пользователь " << username << " не имеет сообщений." << std::endl;
    }
}

void Chat::viewUsers() {
    std::cout << "Зарегистрированные пользователи:" << std::endl;
    for (const auto& pair : users_) {
        std::cout << "- " << pair.first << std::endl;
    }
}

void Chat::loginUser() {
    std::string login, password;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    auto it = users_.find(login);
    if (it != users_.end() && it->second->getPassword() == password) {
        std::cout << "Вы успешно вошли в чат!" << std::endl;
        std::cout << std::endl;
        std::cout << "Здравствуйте, " << it->second->getName() << "." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        currentUser_ = it->second;

        while (true) {
            std::cout << "Выберите действие:" << std::endl << std::endl;
            std::cout << "1. Отправить сообщение" << std::endl;
            std::cout << "2. Прочитать сообщения" << std::endl;
            std::cout << "3. Просмотреть зарегистрированных пользователей" << std::endl;
            std::cout << "4. Выйти из чата" << std::endl;
            std::cout << "---------------------" << std::endl << std::endl;

            int choice;
            std::cin >> choice;
            std::cout << "---------------------" << std::endl << std::endl;

            if (choice == 1) {
                std::string recipient, message;
                std::cout << "Введите имя получателя: ";
                std::cin >> recipient;
                std::cout << "Введите текст сообщения: ";
                std::cin.ignore(); // Очистка буфера ввода перед использованием std::getline()
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
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
            }
        }
    }
    else {
        std::cout << "Пользователь с таким логином и паролем не найден." << std::endl;
        std::cout << "---------------------" << std::endl << std::endl;
        std::cout << "Выберите пункт: " << std::endl << std::endl;
    }
}
