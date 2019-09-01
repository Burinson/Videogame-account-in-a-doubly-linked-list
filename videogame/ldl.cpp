#include "ldl.h"

LDL::LDL()
{
    head = tail = nullptr;
    count = 0;
}

LDL::~LDL()
{

}

void LDL::push_back(Account a)
{
    Node *n = new Node(a);
    if (empty()) {
        head = n;
    } else {
        n->prev = tail;
        tail->next = n;
    }
    tail = n;
    count++;
}

int LDL::size() {
    return count;
}
void LDL::remove(int pos)
{
    Node *aux = head;
    if (count == 1) {
        head = tail = nullptr;
    }
    for(int i = 0; i < pos; ++i) {
        aux = aux->next;
    }
    if (aux->next)
        aux->next->prev = aux->prev;
    else {
        tail = aux->prev;
        tail->next = nullptr;
    }
    if (aux->prev)
        aux->prev->next = aux->next;
    else{
        head = aux->next;
        head->prev = nullptr;
    }

    count--;
    delete aux;
}

bool LDL::empty()
{
    return count == 0;
}

void LDL::show(int id)
{
    cout << "----------------------" << endl;
    cout << "Nombre: " << (*this)[id].getName() << endl;
    cout << "Correo: " << (*this)[id].getEmail() << endl;
    cout << "Nombre de usuario: " << (*this)[id].getUsername() << endl;
    cout << "Contraseña: " << (*this)[id].getPassword() << endl;
    cout << "----------------------" << endl;
}

void LDL::show()
{

    cout << "----------------------" << endl;
    for(int i = 0; i < size(); ++i) {
        cout << i << endl;
        cout << "Nombre: " << (*this)[i].getName() << endl;
        cout << "Correo: " << (*this)[i].getEmail() << endl;
        cout << "Nombre de usuario: " << (*this)[i].getUsername() << endl;
        cout << "Contraseña: " << (*this)[i].getPassword() << endl;
        cout << "----------------------" << endl;
    }
}

int LDL::authenticate(string u, string p)
{
    for(int i = 0; i < size(); ++i) {
        if ((*this)[i].getUsername() == u && (*this)[i].getPassword() == p) {
            return i;
        }
    }
    return -1;
}

void LDL::loadFile()
{
    ifstream fin("accounts.txt", ios::app);
    if (fin.fail())
        cerr << "Ocurrió un error al abrir el archivo" << endl;

    string name, email, username, password, line;
    while(getline(fin, line)) {
        stringstream ss(line);
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');

        Account a(name, email, username, password);
        push_back(a);
    }
    fin.close();
}

void LDL::saveFile()
{
    ofstream fout("accounts.txt");
    if (fout.fail())
        cerr << "Ocurrió un error al abrir el archivo" << endl;

    for(int i = 0; i < size(); ++i) {
        fout << (*this)[i].getName() << "|" << (*this)[i].getEmail() << "|" << (*this)[i].getUsername() << "|" << (*this)[i].getPassword() << endl;
    }
    fout.close();
}

bool LDL::emailExists(string email)
{
    for(int i = 0; i < size(); ++i) {
        if ((*this)[i].getEmail() ==  email)
            return true;
    }
    return false;
}

bool LDL::usernameExists(string username)
{
    for(int i = 0; i < size(); ++i) {
        if ((*this)[i].getUsername() ==  username)
            return true;
    }
    return false;
}


Node::Node()
{
    next = prev = nullptr;
}

Node::Node(Account a)
{
    this->setData(a);
    next = prev = nullptr;
}

Account *Node::getData()
{
    return &data;
}

void Node::setData(const Account &value)
{
    data = value;
}

Node *Node::getNext() const
{
    return next;
}

void Node::setNext(Node *value)
{
    next = value;
}

Node *Node::getPrev() const
{
    return prev;
}

void Node::setPrev(Node *value)
{
    prev = value;
}

bool LDL::validEmail(string str)
{
    return str.find('@') != string::npos;
}

bool LDL::valid(string str)
{
    for(auto x : str) {
        if (x == '|')
            return false;
    }
    return true;
}

bool LDL::validPos(int pos)
{
    return (pos < count && pos > 0);
}




