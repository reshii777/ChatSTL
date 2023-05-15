#include "Message.h"

Message::Message(User* sender, const std::string& text)
    : sender(sender), text(text) {}

User* Message::getSender() const {
    return sender;
}

std::string Message::getText() const {
    return text;
}

void Message::setSender(User* sender) {
    this->sender = sender;
}

void Message::setText(const std::string& text) {
    this->text = text;
}
