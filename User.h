#pragma once

#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(const std::string& username, const std::string& password);

    std::string getName() const;
    std::string getPassword() const;
};