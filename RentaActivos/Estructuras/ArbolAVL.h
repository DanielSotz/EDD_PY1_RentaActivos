#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "NodoAVL.h"


class ArbolAVL
{
    public:
        NodoAVL * root;
        int size;

        ArbolAVL();

        void insertar(string,string,string);
        NodoAVL* insertar2(NodoAVL*,string,string,string);

        int getBalance(NodoAVL*);
        int getAltura(NodoAVL*);

        NodoAVL* rot_derecha(NodoAVL*);
        NodoAVL* rot_izquierda(NodoAVL*);

        NodoAVL* eliminar(string);
        NodoAVL* Del_Nodo(NodoAVL*,string);
        NodoAVL* minValueNodo(NodoAVL*);


};

#endif // ARBOLAVL_H
