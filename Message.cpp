#include "Message.h"

// Конструктор класса Message.
// Инициализирует отправителя и текст сообщения.
Message::Message(User* sender, const std::string& text)
    : sender(sender), text(text) {
}

// Возвращает указатель на отправителя сообщения.
User* Message::getSender() const {
    return sender;
}

// Возвращает текст сообщения.
std::string Message::getText() const {
    return text;  
}

// Устанавливает отправителя сообщения.
void Message::setSender(User* sender) {
    this->sender = sender;
}

// Устанавливает текст сообщения.
void Message::setText(const std::string& text) {
    this->text = text;  
}
