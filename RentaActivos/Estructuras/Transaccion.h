#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
using namespace std;

class Transaccion
{
    public:
        Transaccion(string,string,string,string,string,string,string);

        string idtransaccion, idactivo, usuario;
        string dep, emp;
        string fecha, tiempo;

};

#endif // TRANSACCION_H
