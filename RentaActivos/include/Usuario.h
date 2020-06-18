#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario
{
    public:
        Usuario(string,string,string);

        string idusuario, nombre, contrasenia;
};

#endif // USUARIO_H
