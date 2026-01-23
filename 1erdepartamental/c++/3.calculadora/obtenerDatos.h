#include <iostream>
using namespace std;

class obtener_datos {
public:
    double a;
    double b;
    void pedir_datos () {
        cout << "ingresa tu primer digito" << endl;
        cin >> a;
        cout << "ingresa tu segundo digito" << endl;
        cin >> b;
    }
};