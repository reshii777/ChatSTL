#pragma once

#include <string>
#include "User.h"

class Message {
private:
    User* sender;
    std::string text;

public:
    Message(User* sender, const std::string& text);

    User* getSender() const;
    std::string getText() const;

    void setSender(User* sender);
    void setText(const std::string& text);
};
