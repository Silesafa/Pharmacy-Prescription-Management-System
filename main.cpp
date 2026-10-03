//Proyecto #2 Introducción a la computación
// Andrês Cêspedes Siles
// Primer cuatrimestre 2024
//Realizado el 7/4/2024

//Referencias
//Deitel & Deitel. (2021). Cómo Programar en C++. Pearson Education - UNED. México.
//https://www.youtube.com/watch?v=dJzLmjSJc2c&list=PLWtYZ2ejMVJlUu1rEHLC0i_oibctkl0Vh
// https://www.youtube.com/watch?v=RBZidsPGkfs&t=319s
//Tutorias UNED
// "Manejo de archivos" del tutor Klever Picado Rivera.


#include <iostream> //Estandad de C++
#include <iomanip>// Uso de setw
#include <cctype>// Uso de tolower y toupper
#include <fstream> // libreria para manipular archivos
#include <stdlib.h>// System("cls") atoi & atof
#include <string> //libreria para manipular cadenas.
#include<math.h> //libreria para realizar operaciones matemáticas
#include <locale.h>// para declarar funciones setlocale
#include <limits>//Librería para el uso de numeric_limits
#include <windows.h>//Uso de SetConsole
#include <stdio.h> //entrada y salida estandar, para declarar funciones

using namespace std;

void AgregaMedicamentos();
void AgregaAsociaciones();
void RegistrarReceta();
void ReporteCatalogo();
void ImprimeReceta();


string ConvertirAMinuscula(string cadena);
string ConvertirAMayuscula(string cadena);

 int codigo;
 float cantidad;
 int Numero=1000;
 float Cant ;
 string NombreMedi;
 string respuesta = "";
 string nombre;
 string indicacion;

 int main(){



 setlocale(LC_CTYPE,"Spanish");// para leer y escribir caracteres en español
 setlocale(LC_ALL,"spanish");// para aceptar tildes
 SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
 SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

int opcionMenu;

do {
    system("CLS");

cout << "-----------------Menú Principal-----------------" << endl;
        cout << "   " << endl;
        cout << "1. Ingresar Productos" << endl;
        cout << "2. Ingresar asociaciones con productos" << endl;
        cout << "3. Registra una receta "<< endl;
        cout << "4. Reporte de catálogo de Productos" << endl;
        cout << "5. Reporte impresión de la receta" << endl;
        cout << "6. Salir " << endl;
        cout << "   " << endl;
        cout << "   " << endl;
        cout << "Seleccione una opcion:" << endl;
        cin >> opcionMenu;
        cin.ignore();

        system("CLS");

        if(!cin.good())//Verifica que no se ingresen letras en una variable de tipo entero
        {
            //Se muestra mensaje de advertencia
           cout << "Para el Menú solo esta permitido el ingreso de números" <<endl;
          //Se limpia la información agregada en la variable
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');

          //Espera el inreso de una tecla para continuar
          system("PAUSE");
        }
         else{

        switch (opcionMenu)

      {

      case 1:

         {

               AgregaMedicamentos();


                break;


         }



      case 2:{
                  AgregaAsociaciones();



                break;
      }
      case 3:
          {

                RegistrarReceta();


                break;
          }

      case 4:{
                   ReporteCatalogo();

                   break;
              }





           case 5:{

                   ImprimeReceta();

                 break;
           }




      case 6:

          cout << "6. Salir del Programa" << endl;
           system("pause");// pausar ejecucion
           system("cls"); // limpiar pantalla

                break;

           default:
                cout << "Opcion invalida, vuelva a intentarlo." << endl;
                cout << "Debe ingresar un número valido entre 1 y 6" << endl;
                cout << "   " << endl;

                system("pause");
                system("cls");

      }


      }

 }

 while (opcionMenu != 6);
       cout << "Muchas Gracias, Hasta pronto" << endl;
 return 0;
}


void AgregaMedicamentos()
{


   do{

        ofstream Medicamentos("MEDICAMENTOS.TXT",ios::app);// crear y escribir en archivos, no se borre, se concatenee

        if (!Medicamentos){
            cout << "No se ha podido obtener el archivo Medicamentos.txt" << endl;
                           }

                cout << "Ingresar código" << endl;
                cin >> codigo;
                 if (!cin.good()){
                      cout << " Solo se permite ingreso de números " << endl;
                       cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');// solo ingresar números
                                 }
                 else{
                      cout << "   " << endl;
                      cout << "Ingresar Nombre" << endl;
                       cin.ignore();
                        cin >> NombreMedi;
                         ConvertirAMayuscula(NombreMedi);
                          cout << "   " << endl;
                        cout << "Ingresar cantidad" << endl;
                        cin >> cantidad;
                         if (!cin.good()){
                         cout << " Solo se permite ingreso de números " << endl;
                          cin.clear();
                           cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                 }
                         }

              do{

                   cout << "Desea ingresar el medicamento? (S/N)" << endl;
                   cin >> respuesta;
                    cin.ignore();

                        if(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n")
                            {
                            cout << "Respuesta invalida" << endl;
                             }

                          system("pause");
                          system("CLS");

                 }while(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n");

                   if (ConvertirAMinuscula(respuesta) == "s"){


                        Medicamentos << codigo<<  " " << NombreMedi <<" " << cantidad<< endl;//Ingresa el nuevo registro

                    }



            Medicamentos.close();


    }while(ConvertirAMinuscula(respuesta) == "s");

}
    //Convierte el texto en minúcula
string ConvertirAMinuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++)
  {
      //tolower convierte cualquier texto en minúscula
    cadena[i] = tolower(cadena[i]);
  }
  return cadena;
}


void AgregaAsociaciones()
{
       string PalabraAsociativa;
   do{

        ofstream Claves("CLAVES.TXT",ios::app); // Escritura, no se borre y se concatene

        if (!Claves){
            cout << "No se ha podido obtener el archivo CLAVES.txt" << endl;
                           }
         else{
                cout << "Ingresar código" << endl;
                cin >> codigo;
                 if (!cin.good()){
                     cout << " Solo se permite ingreso de números " << endl;
                       cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(),'\n');


                                 }


                  else{
                cout << "   " << endl;
                cout << "Ingresar Palabra Asociativa única" << endl;
                   cin.ignore();
                     cin >>PalabraAsociativa;
                     ConvertirAMayuscula(PalabraAsociativa);
                     cout << "   " << endl;
                      }
                   do{

                cout << "Desea ingresar la asociación? (S/N)" << endl;
                cin >> respuesta;
                cin.ignore();

                    if(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n")
                       {
                            cout << "Respuesta invalida" << endl;
                       }

                       if(ConvertirAMinuscula(respuesta) == "s" ){

                        bool encontrado = false;

                        string nombreArchivo = "MEDICAMENTOS.txt";
                        ifstream archivo(nombreArchivo.c_str());
                        string linea;
                        // Obtener línea de archivo, y almacenar contenido en "linea"
                        while (getline(archivo, linea)) {

                            char texto[1000];  //le ponemos un número determinado de caracters

                            strcpy(texto, linea.c_str()); //copia el contenido de un string



                             stringstream ss{texto}; //para extraer valores  de una cadena
                              string codigoTxt;
                               getline(ss, codigoTxt, ' ');
                               string nombreTxt;
                               getline(ss, nombreTxt);



                            if(codigo == atoi(codigoTxt.c_str())){ //Atoi convierte una serie de caracteres a un valor entero
                                    Claves << codigo<<  " " << nombreTxt <<  " " << PalabraAsociativa <<endl;//Ingresa el nuevo registro

                                    encontrado = true;



                                    break;


                            }
                        }

                        if(encontrado == false){
                            cout << "LA INDICACION NO ES CORRECTA" << endl;
                            system("pause");
                        }

                       }


                       system("CLS");

                 }while(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n");

             }


            Claves.close();


    }while(ConvertirAMinuscula(respuesta) == "s");

}



void RegistrarReceta()
{




  do{
        ofstream Receta("RECETA.TXT",ios::app);// Escritura, no se borre y se concatene


        if (!Receta){
            cout << "No se ha podido obtener el archivo RECETA.txt" << endl;
                    }
                cout << "Número de receta" <<"   "<< Numero<< endl;
                Numero++;
                cout << "   " << endl;
                cout << "Ingresar Nombre del paciente" << endl;
                   getline(cin,nombre);
                    cout << "   " << endl;
                    cout << "Ingresar Indicación" << endl;
                   getline(cin,indicacion);
                     cout << "   " << endl;
                     cout << "Ingresar código" << endl;
                     cin >> codigo;
                     if (!cin.good()){
                     cout << " Solo se permite ingreso de números " << endl;
                       cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(),'\n');
                     }
                   cout << "Ingresar cantidad" << endl;
                        cin >> Cant;
                   if (!cin.good()){
                     cout << " Solo se permite ingreso de números " << endl;
                       cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                 }




                 do{

                  cout << "Registrar Receta? (S/N)" << endl;
                  cin >> respuesta;
                   cin.ignore();

                    if(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n")
                    {
                        cout << "Respuesta invalida" << endl;
                    }


                    if (ConvertirAMinuscula(respuesta) == "s"){
                        Receta<< Numero<<  " "<< codigo<<  " " << nombre<< " " << indicacion<<" " << Cant<< endl;;//Ingresa el nuevo registro
                    }

                    system("pause");
                    system("CLS");



                 }while(ConvertirAMinuscula(respuesta) != "s" && ConvertirAMinuscula(respuesta) != "n");



                   Receta.close();


    }while(ConvertirAMinuscula(respuesta) == "s");

  }

void ReporteCatalogo(){

   ifstream Medicamentos; // lectura de archivos


          Medicamentos.open ("MEDICAMENTOS.TXT",ios::in);  //Abrimos archivo en modo de lectura

            if (Medicamentos.fail ()){
                cout<< "No se pudo abrir archivo";
                exit(1);
            }
               while (!Medicamentos.eof()) {



                        Medicamentos>>codigo;
                        Medicamentos>>NombreMedi;
                        Medicamentos>>cantidad;

                cout<< "************LISTA DE PRODUCTOS***********" << endl;
                cout<<setw(15)<<"Código"<<setw(15)<<"Descripción"<<setw(15)<<"Cantidad"<< endl;
                cout<<setw(15)<< codigo<< setw(15)<< NombreMedi<< setw(15)<<cantidad  <<setw(15)<<endl;

                           system("pause");
                            system("CLS");
                                }


              Medicamentos.close();


}

void ImprimeReceta()
{

       ifstream Receta;


                Receta.open ("RECETA.TXT",ios::in);//Abrimos archivo en modo de lectura
                if (Receta.fail ()){
                cout<< "No se pudo abrir archivo";
                exit(1);
            }

            while (!Receta.eof())
                {

                        Receta>>Numero;
                        Receta>>nombre;
                        Receta>>codigo;
                        Receta>>NombreMedi;
                        Receta>>indicacion;
                        Receta>>Cant;


                   cout <<"Receta No."<< "   " << Numero<< endl;
                   cout << "   " << endl;
                   cout << "   " << "  Paciente  " << "   " << endl;
                   cout << "   " << nombre<< "   " <<endl;
                   cout << "   " << endl;
                   cout << "   " << "  Medicamento  " << "   " << endl;
                   cout << codigo<<   NombreMedi   << "   " << endl;
                   cout << indicacion << endl;
                   cout << "Cantidad" <<"   " << Cant<< endl;
                   cout << "   " << endl;



                    system("pause");
                    system("CLS");

                }


    Receta.close();

}

   //Convierte el texto a mayúscula
string ConvertirAMayuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++)
  {
      //toupper convierte cualquier texto en mayúscula
    cadena[i] = toupper(cadena[i]);
  }
  return cadena;
}




