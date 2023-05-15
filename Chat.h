#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "User.h"
#include "Message.h"

class Chat {
private:
    User* currentUser_;  // Текущий пользователь
    std::unordered_map<std::string, User*> users_;  // Коллекция пользователей
    std::unordered_map<std::string, std::vector<Message>> messages;  // Коллекция сообщений

public:
    Chat();  // Конструктор класса Chat
    ~Chat();  // Деструктор класса Chat

    void registerUser();  // Регистрация нового пользователя
    void sendGroupMessage(const std::string& message);  // Отправка группового сообщения
    void sendUserMessage(User* sender, const std::string& recipient, const std::string& message);  // Отправка сообщения пользователю
    void viewMessages();  // Просмотр сообщений
    void viewUsers();  // Просмотр пользователей
    void loginUser();  // Вход пользователя в систему
};
