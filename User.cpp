#include "User.h"

// Конструктор класса User.
    // Инициализирует имя и пароль пользователя.
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
}

// Возвращает имя пользователя.
std::string User::getName() const {
    return username;
}

// Возвращает пароль пользователя.
std::string User::getPassword() const {
    return password;
}
