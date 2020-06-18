#include <iostream>
#include <conio.h>

#include <stdlib.h>
#include <time.h>

#include "Matriz.h"
#include "ArbolAVL.h"



using namespace std;

Matriz *mat = new Matriz();
ArbolAVL *arb = new ArbolAVL();

string generarCodigo()
{
    string codigo ="";
    string cod;

    string vec[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9"};
    int num;
    srand(time(NULL));

    for(int c = 1; c <= 15; c++)
    {
        num = 0+ rand() % (37 - 1);
        cod= vec[num];

        codigo=codigo+cod;
        cout << num<< endl;
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
    bool existe= false;
    bool activo;
    bool ambos;
    bool ambos1;


    while (men)
    {
        int opcion = 0;

        string opcionjug1="";
        string opcionjug2="";
        string usuario, contra, nombre,depar,empre;

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
                        cout << "--------------- Menu Administrador --------------"<< endl;
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
                                arb->insertar(usuario,contra,nombre);
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

            }

            else
            {
                existe= mat->buscarUsuario(depar,empre,usuario);
                if(existe)
                    cout << "Usuario ingresa"<< endl;
                else
                    cout << "Usuario no esta registrado"<< endl;
            }
            _getch();
            break;

        case 2:
            system("cls");
            cout << "-------------- Renta de Activos -------------"<< endl;
            cout << "--------------- INICIAR SESION --------------"<< endl;
            cout << "Ingrese usuario"<< endl;
            cin >> usuario;
            cout << "Ingrese contraseña"<< endl;
            cin >> contra;
            existe= mat->buscarUsuario(depar,empre,usuario);
            if(usuario.compare("admin")==0)
            {
                if(contra.compare("123"))
                    cout << "ADMINISTRADOR INGRESO"<< endl;
            }
            else
            {
                if(existe)
                cout << "Usuario ya existe en esa empresa y departamento"<< endl;
            else
                mat->insertar(depar,empre,usuario,contra,nombre);
                arb->insertar(usuario,contra,nombre);

            }


            _getch();
            break;
        case 3:
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
            existe= mat->buscarUsuario(depar,empre,usuario);
            if(existe)
                cout << "Usuario ya existe en esa empresa y departamento"<< endl;
            else
                mat->insertar(depar,empre,usuario,contra,nombre);
                arb->insertar(usuario,contra,nombre);


            ambos=true;
            activo=true;


            system("cls");
            cout << "--------------J U E G O-------------"<< endl;

            cout << "\n--------- Datos Cola\n";

            cout<< " Fichas ingresadas aletorias correctamente "<<endl;


            _getch();
            break;
        case 4:
            cout << "Ingrese url de Json\n";
             _getch();
            break;
        case 5:
            men2=false;
            while(men2){

            system("cls");
            cout << "***********REPORTES***********\n\n";
            cout << "1. Lista Doblemente Enlazada Circurlar Diccionario" << endl;
            cout << "2. Arbol Binario de Jugadores" << endl;
            cout << "3. Recorrido Preorden Arbol" << endl;
            cout << "4. Recorrido Inorden Arbol" << endl;
            cout << "5. Recorrido Postorden Arbol" << endl;
            cout << "6. Grafica cola de fichas" << endl;
            cout << "6. Exit" << endl;

            cout << "Selecciona una opcion\n"; cin >> opcion;
            cout << "opcion: " << opcion << endl;


        }
         _getch();
        break;


        default:
            men = false;
            break;
        }

    }




    return 0;
}
