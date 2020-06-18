#include "Nodom.h"

Nodom::Nodom()
{
}
Nodom::Nodom(Usuario* user, ArbolAVL* arb)
{
    this->usuario = user;
    this->arbol= arb;

}

