#include "ArbolAVL.h"

ArbolAVL::ArbolAVL()
{
    root = 0;
    size=0;
}

void ArbolAVL::insertar(string activo, string desc, string idact)
{

    root = insertar2(root, activo,desc,idact);
    cout << "Ingresado en arbol avl"<< root->activo << endl;
}

NodoAVL* ArbolAVL::insertar2(NodoAVL* actual, string activo, string desc,string idact)
{
    if( actual == NULL)
    {
        root = new NodoAVL(activo,desc,idact);
        size++;
        return root;
    }

    if( idact.compare(actual->idactivo) < 0)
        actual->left = insertar2(actual->left,activo,desc,idact);
    else if (idact.compare(actual->idactivo)> 0)
        actual->right = insertar2(actual->right,activo,desc,idact);
    else
        return actual;

    //Paso 2
    actual->height = 1 + max(getAltura(actual->left),getAltura(actual->right) );

    //Paso 3
    int balance = getBalance(actual);
    actual->fe= getAltura(actual->right)- getAltura(actual->left);

    // 1 simple izquierda

    if(balance>1 && (idact.compare(actual->left->idactivo) < 0) )
    {
       return rot_derecha(actual);
    }
    // 2 simple derecha
    if(balance<-1 && (idact.compare(actual->right->idactivo) >0))
    {
        return rot_izquierda(actual);
    }
    // 3 doble izquierda
    if(balance >1 && (idact.compare(actual->right->idactivo) >0))
    {
        actual->left = rot_izquierda(actual->left);
        return rot_derecha(actual);
    }
    // 4 doble derecha
    if(balance<-1 && (idact.compare(actual->right->idactivo)<0))
    {
        actual->right = rot_derecha(actual->right);
        return rot_izquierda(actual);
    }

    return actual;


}


int ArbolAVL::getBalance(NodoAVL* root)
{
    if(root == NULL)
        return 0;
    return getAltura(root->left) - getAltura(root->right);
}

int ArbolAVL::getAltura(NodoAVL* root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

NodoAVL* ArbolAVL::rot_derecha(NodoAVL* z)
{
    NodoAVL* y = z->left;
    NodoAVL* T2= y->right;

    //rotacion
    y->right=z;
    z->left= T2;

    //actualizar altura
    z->height=max(getAltura(z->left),getAltura(z->right)) +1;
    y->height=max(getAltura(y->left),getAltura(y->right)) +1;

    z->fe = getAltura(z->right)- getAltura(z->left);
    y->fe = getAltura(y->right)- getAltura(y->left);

    //retorna nuevo root
    return y;
}

NodoAVL* ArbolAVL::rot_izquierda(NodoAVL* z)
{
    NodoAVL* y = z->right;
    NodoAVL* T2= y->left;

    //rotacion
    y->left=z;
    z->right= T2;

    //actualizar altura
    z->height=max(getAltura(z->left),getAltura(z->right)) +1;
    y->height=max(getAltura(y->left),getAltura(y->right)) +1;

    z->fe = getAltura(z->right)- getAltura(z->left);
    y->fe = getAltura(y->right)- getAltura(y->left);

    //retorna nuevo root
    return y;
}

NodoAVL* ArbolAVL::eliminar(string nombre)
{
    return this->root = Del_Nodo(root,nombre);
}

NodoAVL* ArbolAVL::Del_Nodo(NodoAVL* actual, string nombre)
{
    if(actual==NULL)
    {
        return actual;
    }

    if(nombre.compare(actual->idactivo)<0)
        actual->left = Del_Nodo(actual->left,nombre);
    else if(nombre.compare(actual->idactivo)>0)
        actual->right= Del_Nodo(actual->right,nombre);
    else
    {
        if((actual->left ==NULL) || (actual->right == NULL))
        {
            NodoAVL*temp= NULL;
            if(temp == actual->left)
                temp = actual->right;
            else
                temp = actual->left;

            //No hijos
            if(temp == NULL)
            {
                temp = actual;
                actual = NULL;
            }
            else //caso un hijo
                actual = temp;  // copia el contenido del hijo no vacio
        }
        else
        {
            //nodo con 2 hijos: obtener el inorder
            //sucesor el mas pequeño del arbol subderecho
            NodoAVL* temp= minValueNodo(actual->right);

            //pasar los datos al actual nodo
            actual->idactivo= temp->idactivo;
            actual->activo= temp->activo;
            actual->descripcion = temp->descripcion;

            //eliminar el inorden sucesor
            actual->right = Del_Nodo(actual->right,temp->idactivo);

        }

    }

    // If the tree had only one node then return
    if (actual == NULL)
        return actual;

    //actualizar altura
    actual->height = max(getAltura(actual->left),getAltura(actual->right)) +1;
    //actualizar fe
    actual->fe = getAltura(actual->right) - getAltura(actual->left);

    //PASO 3: ET THE BALANCE FACTOR OF THIS NODE (to check whether

    int balance = getBalance(actual);

    // 1 simple izquierda

    if(balance>1 && getBalance(actual->left) >= 0 )
    {
       return rot_derecha(actual);
    }
    // 2 simple derecha
    if(balance>1 &&  getBalance(actual->left) <0 )
    {
        actual->left = rot_izquierda(actual->left);
        return rot_derecha(actual);
    }
    // 3 doble izquierda
    if(balance <-1 &&  getBalance(actual->right)<=0)
    {
        return rot_izquierda(actual);
    }
    // 4 doble derecha
    if(balance<-1 && getBalance(actual->right)>0)
    {
        actual->right = rot_derecha(actual->right);
        return rot_izquierda(actual);
    }

    return actual;

}

NodoAVL* ArbolAVL::minValueNodo(NodoAVL*nodo)
{
    NodoAVL * current = nodo;

    /* loop down to find the leftmost leaf */
    while(current->left != NULL)
        current = current->left;

    return current;
}
