#pragma once

#include <string>
#include "User.h"

class Message {
private:
    User* sender;  // Указатель на отправителя сообщения
    std::string text;  // Текст сообщения

public:
    Message(User* sender, const std::string& text);  // Конструктор класса Message

    User* getSender() const;  // Получить отправителя сообщения
    std::string getText() const;  // Получить текст сообщения

    void setSender(User* sender);  // Установить отправителя сообщения
    void setText(const std::string& text);  // Установить текст сообщения
};
