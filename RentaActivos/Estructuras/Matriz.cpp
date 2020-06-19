#include "Matriz.h"

Matriz::Matriz()
{
    raiz = new Nodom();
    raiz->departamento="RAIZ";
    raiz->empresa="RAIZ";
    Usuario *user = new Usuario("admin","123","admin");
    raiz->usuario = user;

    tamanio=0;
}

Nodom* Matriz::BuscarFila(string empresa)
{
	Nodom* temp = raiz;
	while (temp != NULL)
	{
		if (temp->empresa == empresa)
		{
			return temp;
		}
		temp = temp->abajo;
	}
	return nullptr;
}

Nodom* Matriz::BuscarCol(string departamento)
{
	Nodom* temp = raiz;
	while (temp != NULL)
	{
		if (temp->departamento == departamento)
		{
			return temp;
		}
		temp = temp->sig;
	}
	return nullptr;
}


void Matriz::insertar(string departamento, string empresa, string usuario, string contra, string nombre)
{
    Usuario *user = new Usuario(usuario,contra,nombre);
    ArbolAVL* arbol = new ArbolAVL();
	Nodom* nuevo = new Nodom(user,arbol);
	Nodom* NodoCol = BuscarCol(departamento);
	Nodom* NodoFila = BuscarFila(empresa);
	nuevo->departamento = departamento;
	nuevo->empresa = empresa;


	//1)Col no, Fila no
	if (NodoCol == NULL && NodoFila == NULL) {
		cout << "Caso1\n";
		NodoCol = CrearCol(departamento);
		NodoFila = CrearFila(empresa);
		//insertamos ordendo en columnna
		nuevo = InsertarCol(nuevo, NodoFila);
		//insertamos ordendao en fila
		nuevo = InsertarFila(nuevo, NodoCol);

	}
	//3)Col no, Fila si
	else if (NodoCol == NULL && NodoFila != NULL ) {
		cout << "Caso3\n";
		NodoCol = CrearCol(departamento);
		//insertamos ordendo en columnna
		nuevo = InsertarCol(nuevo, NodoFila);
		//insertamos ordendao en fila
		nuevo = InsertarFila(nuevo, NodoCol);

	}

	//5)Col si, Fila no
	else if (NodoCol != NULL && NodoFila == NULL) {
		cout << "Caso5\n";
		NodoFila = CrearFila(empresa);
		//insertamos ordendo en columnna
		nuevo = InsertarCol(nuevo, NodoFila);
		//insertamos ordendao en fila
		nuevo = InsertarFila(nuevo, NodoCol);


	}

	//7)Col si, Fila si
	else if (NodoCol != NULL && NodoFila != NULL ) {
		cout << "Caso7\n";
		//insertamos ordendo en columnna
		nuevo = InsertarCol(nuevo, NodoFila); //inserta en eje z

	}

	cout << nuevo->departamento << nuevo->empresa << " user: " << nuevo->usuario->idusuario << " Insertado\n";
	tamanio++;
}

Nodom* Matriz::InsertarCol(Nodom* nuevo, Nodom* cabezaCol)
{
	Nodom* temp = cabezaCol;
	while (true)
	{
		if (temp->departamento == nuevo->departamento)
        {
            while(temp != NULL)
            {
                if(temp->atras != NULL)
                {
                    temp = temp->atras;
                }
                else{
                    break;
                }
            }

            temp->atras = nuevo;
            nuevo->delante = temp;

            return nuevo;


		}
		else if (temp->sig != NULL) {
			temp = temp->sig;
		}
		else {
			//tengo que insertarlo despues de temp
			break;
		}
	}

	temp->sig = nuevo;
    nuevo->ant = temp;

	return nuevo;
}

Nodom* Matriz::InsertarFila(Nodom* nuevo, Nodom* cabezaFila)
{
	Nodom* temp = cabezaFila;
	while (true)
	{
		if (temp->empresa == nuevo->empresa) {
			return temp;
		}
		else if (temp->abajo != NULL) {
			temp = temp->abajo;
		}
		else {
			break;
		}
	}

	temp->abajo = nuevo;
    nuevo->arriba= temp;

	return nuevo;
}

Nodom* Matriz::CrearCol(string departamento)
{
	Nodom* cabezaCol = raiz;
	Nodom* nuevo = new Nodom();
	nuevo->departamento = departamento;

	Nodom* columna = InsertarCol(nuevo, cabezaCol);
	return columna;
}

Nodom* Matriz::CrearFila(string empresa)
{
	Nodom* cabezaFila = raiz;
	Nodom* nuevo = new Nodom();
	nuevo->empresa = empresa;
	Nodom* fila = InsertarFila(nuevo, cabezaFila);
	return fila;
}

bool Matriz::buscarUsuario(string departamento, string empresa, string usuario)
{
    Nodom* NodoCol = BuscarCol(departamento);
	Nodom* NodoFila = BuscarFila(empresa);
	bool existe = false;

	if (NodoCol == NULL && NodoFila == NULL)
    {
        return existe;
    }
    else if( NodoCol != NULL && NodoFila != NULL)
    {
        Nodom* temp = NodoCol;

        while(temp != NULL)
        {
            if(temp->empresa == empresa)
            {
             break;
            }
            temp = temp->abajo;
        }

        while(temp!= NULL)
        {
            if(temp->usuario->idusuario == usuario)
            {
                existe=true;
                break;
            }
            temp = temp->atras;
        }
    }

    return existe;
}

Nodom* Matriz::buscarUsuario2(string departamento, string empresa, string usuario)
{
    Nodom* NodoCol = BuscarCol(departamento);
	Nodom* NodoFila = BuscarFila(empresa);
	Nodom* temp;

	if (NodoCol == NULL && NodoFila == NULL)
    {
        return nullptr;
    }
    else if( NodoCol != NULL && NodoFila != NULL)
    {
        temp = NodoCol;

        while(temp != NULL)
        {
            if(temp->empresa == empresa)
            {
             break;
            }
            temp = temp->abajo;
        }

        while(temp!= NULL)
        {
            if(temp->usuario->idusuario == usuario)
            {
                break;
            }
            temp = temp->atras;
        }
    }

    return temp;
}

void Matriz::imprimirTodas()
{
    Nodom* temp = raiz;

    temp = temp->abajo;
    temp = temp->sig;


	while (temp != NULL)
	{
	    Nodom* temp2 = temp;
	    while(temp2 != NULL)
        {
            temp2->arbol->imprimirDisponibles(temp2->arbol->root);
            temp2 = temp2->sig;
        }
		temp = temp->abajo;
	}
}
void Matriz::imprimirARentar(string user)
{
    Nodom* temp = raiz;

    temp = temp->abajo;
    temp = temp->sig;


	while (temp != NULL)
	{
	    Nodom* temp2 = temp;
	    while(temp2 != NULL)
        {
            if( temp2->usuario->nombre != user )
            {
                temp2->arbol->imprimirDisponibles(temp2->arbol->root);
            }

            temp2 = temp2->sig;
        }
		temp = temp->abajo;
	}
}

NodoAVL* Matriz::buscarActivo(string idactivo)
{
    Nodom* temp = raiz;

    temp = temp->abajo;
    temp = temp->sig;

    NodoAVL*resultado =0;



	while (temp != NULL)
	{
	    Nodom* temp2 = temp;
	    while(temp2 != NULL)
        {
            NodoAVL* resultado = temp2->arbol->buscar(idactivo);

            if(resultado !=NULL)
                return resultado;

            temp2 = temp2->sig;
        }
		temp = temp->abajo;
	}

	return resultado;


}



