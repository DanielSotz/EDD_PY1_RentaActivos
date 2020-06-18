#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


#include "Usuario.h"
#include "Nodom.h"

class Matriz
{
    public:

        Nodom* raiz;
        int tamanio;
        Matriz();

        Nodom* BuscarCol(string);
        Nodom* BuscarFila(string);

        Nodom* CrearCol(string);
        Nodom* CrearFila(string);

        Nodom* InsertarCol(Nodom*,Nodom*);
        Nodom* InsertarFila(Nodom*,Nodom*);

        void insertar(string, string, string,string,string);

        bool buscarUsuario(string, string, string);



};

#endif // MATRIZ_H
