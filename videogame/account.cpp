#include "account.h"

string Account::getName() const
{
    return name;
}

void Account::setName(const string &value)
{
    name = value;
}

string Account::getEmail() const
{
    return email;
}

void Account::setEmail(const string &value)
{
    email = value;
}

string Account::getUsername() const
{
    return username;
}

void Account::setUsername(const string &value)
{
    username = value;
}

string Account::getPassword() const
{
    return password;
}

void Account::setPassword(const string &value)
{
    password = value;
}

Account::Account()
{

}

Account::Account(string name, string email, string username, string password)
{
    this->name = name;
    this->email = email;
    this->username = username;
    this->password = password;
}
