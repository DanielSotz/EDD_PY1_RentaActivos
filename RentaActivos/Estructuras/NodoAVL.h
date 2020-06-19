#ifndef NODOAVL_H
#define NODOAVL_H

#include<iostream>
#include<string>

using namespace std;


class NodoAVL
{
    public:

        NodoAVL(string,string,string);

        NodoAVL* left=0;
        NodoAVL* right=0;

        int height;
        int fe;

        string activo;
        bool disponible;
        string descripcion;
        string idactivo;

};

#endif // NODOAVL_H
