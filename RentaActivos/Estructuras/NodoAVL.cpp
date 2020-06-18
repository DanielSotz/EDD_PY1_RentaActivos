#include "NodoAVL.h"

NodoAVL::NodoAVL(string activo,string desc, string idact)
{
    this->activo= activo;
    this->descripcion= desc;
    this->idactivo = idact;

    this->height =1;
    this->fe=0;

}


