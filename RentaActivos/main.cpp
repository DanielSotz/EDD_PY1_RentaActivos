#include <iostream>
#include <conio.h>

#include <stdlib.h>
#include <time.h>

#include "Matriz.h"
#include "Nodom.h"
#include "ArbolAVL.h"
#include "CircularDobre.h"
#include "Transaccion.h"



using namespace std;

Matriz *mat = new Matriz();
CircularDobre <Transaccion*> *lista = new CircularDobre<Transaccion*>();

Transaccion* tran;

ArbolAVL *arbol;
ArbolAVL *avl;



string generarCodigo()
{
    string codigo ="";
    string cod;

    string vec[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9"};
    int num;
    srand(time(NULL));

    for(int c = 1; c <= 5; c++)
    {
        num = 0+ rand() % (37 - 1);
        cod= vec[num];

        codigo=codigo+cod;
    }
    return codigo;
}

string mayusculas(string cadena)
{

    for(int i=0; i< cadena.length();i++)
    {
        cadena[i]= toupper(cadena[i]);
    }

    return cadena;

}

int main()
{
    bool men = true;
    bool men2 = true;
    bool men3= true;
    bool existe= false;

    Nodom *us = new Nodom();
    NodoAVL *el;

    while (men)
    {
        int opcion = 0;
        string usuario, contra, nombre,depar,empre;
        string idactivo, activo,descripcion, eliminar,opp,renta,dias;
        string idtran, fecha, tiempo;

        system("cls");
        cout << "-------------- RENTA DE ACTIVOS -------------"<< endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Exit" << endl;
        cout << "Selecciona una opcion\n"; cin >> opcion;
        cout << "opcion: " << opcion << endl;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "-------------- Renta de Activos -------------"<< endl;
            cout << "--------------- INICIAR SESION --------------"<< endl;
            cout << "Ingrese usuario"<< endl;
            cin >> usuario;
            cout << "Ingrese contraseña"<< endl;
            cin >> contra;
            cout << "Ingrese Departamento"<< endl;
            cin >> depar;
            cout << "Ingrese Empresa"<< endl;
            cin >> empre;
            depar = mayusculas(depar);
            empre = mayusculas(empre);
            if(usuario.compare("admin")==0)
            {
                if(contra.compare("123")==0)
                {
                    men2=true;
                    while(men2)
                    {
                        system("cls");
                        cout << "-------------- Renta de Activos -------------"<< endl;
                        cout << "------------- Menu Administrador ------------"<< endl;
                        cout << "1. Registrar Usuario"<< endl;
                        cout << "2. Reporte Matriz Dispersa"<< endl;
                        cout << "3. Reporte Activos Disponibles de un Departamento"<< endl;
                        cout << "4. Reporte Activos Disponibles de una Empresa"<< endl;
                        cout << "5. Reporte Transacciones"<< endl;
                        cout << "6. Reporte Activos de un Usuario"<< endl;
                        cout << "7. Activos rentados por un Usuario"<< endl;
                        cout << "8. Ordenar Transacciones"<< endl;
                        cout << "9. Salir"<< endl;
                        cout << "Selecciona una opcion\n"; cin >> opcion;
                        cout << "opcion: " << opcion << endl;
                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            cout << "---------- NUEVO USUARIO------------"<< endl;
                            cout << "Ingrese nombre usuario"<< endl;
                            cin >> usuario;
                            cout << "Ingrese contraseña"<< endl;
                            cin >> contra;
                            cout << "Ingrese nombre completo"<< endl;
                            cin >> nombre;
                            cout << "Ingrese Departamento"<< endl;
                            cin >> depar;
                            cout << "Ingrese Empresa"<< endl;
                            cin >> empre;
                            depar = mayusculas(depar);
                            empre = mayusculas(empre);
                            existe= mat->buscarUsuario(depar,empre,usuario);
                            if(existe)
                                cout << "Usuario ya existe en esa empresa y departamento"<< endl;
                            else
                            {
                                mat->insertar(depar,empre,usuario,contra,nombre);
                                _getch();
                            }
                            _getch();
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 8:
                            break;
                        default:
                            men2=false;
                            break;
                        }

                    }

                }
                else
                    cout << "Contraseña de admin incorrecta"<< endl;
            }

            else
            {
                existe= mat->buscarUsuario(depar,empre,usuario);
                if(existe)
                {
                    us= mat->buscarUsuario2(depar,empre,usuario);
                    men2=true;
                    while(men2)
                    {
                        system("cls");
                        cout << "-------------- Renta de Activos -------------"<< endl;
                        cout << "-------------"<< usuario <<"-------------" <<endl;
                        cout << "1. Agregar activo"<< endl;
                        cout << "2. Eliminar activo"<< endl;
                        cout << "3. Modificar activo"<< endl;
                        cout << "4. Rentar Activo"<< endl;
                        cout << "5. Activos Rentados"<< endl;
                        cout << "6. Mis Activos Rentados"<< endl;
                        cout << "7. Cerrar Sesión"<< endl;

                        cout << "Selecciona una opcion\n"; cin >> opcion;
                        cout << "opcion: " << opcion << endl;

                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            cout << "---------- Agregar Activo------------"<< endl;
                            cout << "Ingrese Nombre Activo"<< endl;
                            cin >> activo;
                            cout << "Ingrese Descripcion"<< endl;
                            cin >> descripcion;
                            idactivo = generarCodigo();
                            us->arbol->insertar(activo,descripcion,idactivo);
                            _getch();
                            break;
                        case 2:
                            system("cls");
                            cout << "---------- Eliminar Activo------------"<< endl;
                            us->arbol->imprimir(us->arbol->root);
                            cout << "Ingrese Id Activo a Eliminar"<< endl;
                            cin >> eliminar;
                            el = us->arbol->eliminar(eliminar);
                            if(el !=NULL)
                            {
                                system("cls");
                            cout << "---------- Eliminado Activo------------"<< endl;
                            cout << "Activo Eliminado"<< endl;
                            cout << "ID: "<< eliminar << endl;
                            cout << "Nombre: "<< el->activo <<endl;
                            cout << "Descripcion: "<< el->descripcion << endl;

                            }
                            else
                            {
                                system("cls");
                                cout << "----Activo no existe---"<< endl;
                            }
                            _getch();
                            break;
                        case 3:
                            system("cls");
                            cout << "---------- Modificar Activo------------"<< endl;
                            us->arbol->imprimir(us->arbol->root);
                            cout << "Ingrese Id Activo a Modificar"<< endl;
                            cin >> eliminar;
                            el = us->arbol->buscar(eliminar);
                            if(el !=NULL)
                            {
                                system("cls");
                                cout << "---------- Modificar Activo------------"<< endl;
                                cout << "Ingrese Descripcion nueva:"<< endl;
                                cin >> descripcion;
                                el->descripcion = descripcion;
                                cout << "Activo Modificado"<< endl;
                                cout << "ID= " << eliminar << " ; Nombre= "<<el->activo <<" ; Descripcion= " << descripcion << endl;
                            }
                            else
                            {
                                cout << "idActivo no encontrado"<< endl;
                            }

                            _getch();
                            break;
                        case 4:
                            system("cls");
                            cout << "---------- Catalogo Activos------------"<< endl;
                            mat->imprimirARentar(usuario);
                            cout << "----------1.Rentar Activo------------"<< endl;
                            cout << "Ingrese Id Activo a Rentar"<< endl;
                            cin >> eliminar;
                            el = mat->buscarActivo(eliminar);
                            if(el !=NULL)
                            {
                                cout << "Ingresar dias por Rentar"<< endl;
                                cin >> dias;
                                cout << "Ingresar fecha por Rentar"<< endl;
                                cin >> fecha;
                                el->disponible =false;
                                idtran= generarCodigo();
                                tran= new Transaccion(idtran,eliminar,usuario,depar,empre,fecha,dias);
                                lista->add_last(tran);
                                cout << "Activo Rentado"<< endl;
                                cout << "ID= " << eliminar << " ; Nombre= "<<el->activo <<" ; Descripcion= " << el->descripcion << endl;
                            }
                            else
                            {
                                cout << "idActivo no encontrado"<< endl;
                            }

                            _getch();
                            break;
                        case 5:
                            cout << "---------- Activos Rentados------------"<< endl;
                            break;
                        case 6:
                            cout << "---------- Mis Activos Rentados------------"<< endl;
                            us->arbol->imprimirRentados(us->arbol->root);
                            _getch();
                            break;
                        default:
                            men2=false;
                            break;
                        }


                    }
                }
                else
                    cout << "Usuario no esta registrado"<< endl;
            }

            _getch();
            break;

        case 2:
            system("cls");
            cout << "-------------- Hola -------------"<< endl;
            avl = new  ArbolAVL();
            avl->insertar("act1","activo 1","1");
            avl->insertar("act5","activo 5","5");
            avl->insertar("act8","activo 8","8");
            avl->insertar("act2","activo 2","2");

            avl->graficar();

            _getch();
            break;

        default:
            men = false;
            break;
        }
    }
    return 0;
}
