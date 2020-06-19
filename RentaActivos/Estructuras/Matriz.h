#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;


#include "Usuario.h"
#include "Nodom.h"
#include "ArbolAVL.h"
#include "NodoAVL.h"

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

        Nodom* buscarUsuario2(string, string, string);

        void imprimirTodas();
        void imprimirARentar(string);
        NodoAVL* buscarActivo(string);




};

#endif // MATRIZ_H
