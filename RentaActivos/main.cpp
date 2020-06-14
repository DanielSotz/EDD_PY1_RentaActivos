#include <iostream>


#include <conio.h>

using namespace std;

int main()
{
    bool men = true;
    bool men2 = true;
    bool activo;
    bool ambos;
    bool ambos1;


    while (men)
    {
        int opcion = 0;

        string opcionjug1="";
        string opcionjug2="";
        string jugador;



        string ur = "";
        system("cls");
        cout << "***********RENTA DE ACTIVOS***********\n\n";
        cout << "1. Agregar nuevo jugador" << endl;
        cout << "2. Scoreboard" << endl;
        cout << "3. Iniciar juego" << endl;
        cout << "4. Lectura de Archivo" << endl;
        cout << "5. Reports" << endl;
        cout << "6. Exit" << endl;

        cout << "Selecciona una opcion\n"; cin >> opcion;
        cout << "opcion: " << opcion << endl;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "---------- NUEVO JUGADOR------------"<< endl;
            cout << "Ingrese nombre jugador"<< endl;
            cin >> jugador;

            _getch();
            break;
        case 2:
            system("cls");
            cout << "--------------SCOREBOAD-------------"<< endl;

            _getch();
            break;
        case 3:

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
            cin >> ur;
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
