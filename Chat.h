#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "User.h"
#include "Message.h"

class Chat {
private:
    User* currentUser_;
    std::unordered_map<std::string, User*> users_;
    std::unordered_map<std::string, std::vector<Message>> messages;

public:
    Chat();
    ~Chat();

    void registerUser();
    void sendGroupMessage(const std::string& message);
    void sendUserMessage(User* sender, const std::string& recipient, const std::string& message);
    void viewMessages();
    void viewUsers();
    void loginUser();
};