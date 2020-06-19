#include "Transaccion.h"

Transaccion::Transaccion(string idtra,string idact,string user,string dep,string emp,string fec,string tie)
{
    this->idtransaccion=idtra;
    this->idactivo=idact;
    this->usuario=user;
    this->dep=dep;
    this->emp=emp;
    this->fecha=fec;
    this->tiempo=tie;

}


