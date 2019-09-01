#include <iostream>
#include <vector>
#include <account.h>
#include <fstream>
#include <sstream>
#include <ldl.h>
using namespace std;

int main()
{

    LDL l;
    l.loadFile();
    string name, email, username, password;
    int op;
    do {
        cout << "Menú" << endl;
        cout << "1) Registrar cuenta" << endl;
        cout << "2) Acceder" << endl;
        cout << "3) Mostrar todo" << endl;
        cout << "0) Salir" << endl;
        cin >> op;
        switch(op) {
        case 1: {
            cout << "Nombre: "; cin >> name;;
            cout << "Correo: "; cin >> email;
            cout << "Nombre de usuario: "; cin >> username;
            cout << "Contraseña: "; cin >> password;

            if (l.valid(name) && l.valid(email) && l.valid(username) && l.valid(password) && l.validEmail(email) && !l.emailExists(email) && !l.usernameExists(username)) {
                Account a(name, email, username, password);
                l.push_back(a);
            } else {
                cout << "Uno de estos campos tiene delimitador, el correo es incorrecto o ya existe usuario/correo, intenta de nuevo" << endl;
            }

            break;
        } case 2:
        {
            cout << "Nombre de usuario: "; cin >> username;
            cout << "Contraseña: "; cin >> password;
            int token = l.authenticate(username, password);
            if (token > -1) {
                int op2;
                do {
                cout << "1) Mostrar" << endl;
                cout << "2) Modificar" << endl;
                cout << "3) Eliminar" << endl;
                cout << "0) Regresar" << endl;
                cin >> op2;
                switch(op2) {
                case 1:
                {
                    l.show(token);
                    break;
                }
                case 2:
                {
                    int op3;
                    do {
                        l.show(token);
                        cout << "1) Nombre" << endl;
                        cout << "2) Correo" << endl;
                        cout << "3) Nombre de usuario" << endl;
                        cout << "4) Contraseña" << endl;
                        cout << "0) Regresar" << endl;
                        cin >> op3;
                        switch(op3) {
                        case 1: {
                            cout << "Nombre nuevo: ";
                            cin >> name;
                            if (l.valid(name))
                                l[token].setName(name);
                            else
                                cout << "Uno de estos campos tiene delimitador, intenta de nuevo" << endl;
                            break;
                        }
                        case 2: {
                            cout << "Correo nuevo: "; cin >> email;
                            if (l.valid(email) && l.validEmail(email) && !l.emailExists(email))
                                l[token].setEmail(email);
                            else
                                cout << "Uno de estos campos tiene delimitador, el correo es incorrecto o ya existe, intenta de nuevo" << endl;
                            break;
                        }
                        case 3: {
                            cout << "Nombre de usuario nuevo: "; cin >> username;
                            if (l.valid(username) && !l.usernameExists(username))
                                l[token].setUsername(username);
                            else
                                cout << "Uno de estos campos tiene delimitador, intenta de nuevo" << endl;
                            break;
                        }
                        case 4: {
                            cout << "Contraseña nueva: "; cin >> password;
                            if (l.valid(password))
                                l[token].setPassword(password);
                            else
                                cout << "Uno de estos campos tiene delimitador, intenta de nuevo" << endl;
                            break;
                        }
                        }

                    } while(op3 != 0);
                    break;
                }
                case 3: {
                    l.remove(token);
                    op2 = 0;
                    break;
                }
                }
                } while(op2 != 0);
            } else {
                cout << "Acceso denegado" << endl;
            }
            break;
        }
        case 3:
        {
            l.show();
            break;
        }
        }
    } while(op != 0);

    l.saveFile();

    return 0;
}
