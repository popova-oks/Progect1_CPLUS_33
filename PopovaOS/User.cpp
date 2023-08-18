#include"User.h"

User::User(const std::string& name, const std::string& login, const std::string& password) : _name(name), _login(login), _password(password)
{
    _user_ID = counter;
}

void User::setName(const std::string& name)
{
    _name = name;
}

const std::string& User::getName() const
{
    return _name;
}

void User::setLogin(const std::string& login)
{
    _login = login;
}

const std::string& User::getLogin() const
{
    return _login;
}

void User::setPassword(const std::string& password)
{
    _password = password;
}

const std::string& User::getPassword() const
{
    return _password;
}
