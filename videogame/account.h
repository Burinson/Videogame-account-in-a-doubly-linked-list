#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;

class Account
{
    string name;
    string email;
    string username;
    string password;

public:
    Account();
    Account(string name, string email, string username, string password);
    string getName() const;
    void setName(const string &value);
    string getEmail() const;
    void setEmail(const string &value);
    string getUsername() const;
    void setUsername(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
};

#endif // ACCOUNT_H
