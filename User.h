#pragma once

#include <string>

class User {
public:
    std::string username;  // Имя пользователя
    std::string password;  // Пароль пользователя

    User(const std::string& username, const std::string& password);

    std::string getName() const;  // Возвращает имя пользователя
    std::string getPassword() const;  // Возвращает пароль пользователя
};
