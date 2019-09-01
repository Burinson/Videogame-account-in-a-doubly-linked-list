#ifndef LDL_H
#define LDL_H
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <account.h>

class Node {
public:
    Node();
    friend class LDL;
    Node(Account a);
    Account *getData();
    void setData(const Account &value);

    Node *getNext() const;
    void setNext(Node *value);

    Node *getPrev() const;
    void setPrev(Node *value);

private:
    Account data;
    Node *next;
    Node *prev;

};

class LDL
{
public:
    LDL();
    ~LDL();
    friend class Node;
    void push_back(Account a);
    void remove(int pos);
    bool empty();
    void show();
    void show(int id);
    int size();
    int authenticate(string u, string p);
    void loadFile();
    void saveFile();
    bool emailExists(string email);
    bool usernameExists(string username);
    bool validEmail(string str);
    bool valid(string str);
    bool validPos(int pos);
    Account &operator [](int pos) {
        Node *a = head;
        for(int i = 0; i < pos; ++i) {
            a = a->getNext();
        }
        return a->data;
    }



private:
    Node *head;
    Node *tail;
    int count;
};

#endif // LDL_H
