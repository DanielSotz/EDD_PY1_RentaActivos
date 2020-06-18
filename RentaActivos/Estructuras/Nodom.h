#ifndef NODOM_H
#define NODOM_H

#include<iostream>
#include<string>

#include "Usuario.h"
#include "ArbolAVL.h"

using namespace std;


class Nodom
{
    public:
        Nodom();
        Nodom(Usuario*);

        ArbolAVL* arbol=0;

        Usuario *usuario =0;
        string empresa;
        string departamento;

        Nodom* sig=0;
        Nodom* ant=0;
        Nodom* arriba=0;
        Nodom* abajo=0;
        Nodom* delante=0;
        Nodom* atras=0;
};

#endif // NODOM_H
