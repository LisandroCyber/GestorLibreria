#include <iostream>
#include <string>
#include "Resolucion.h"
#include "socio.h"
#include "prestamo.h"

void Resolucion::punto3(Prestamo *vecPrestamos){

    int vecSocio[10]={};

    for(int j=0 ; j < 10 ;j++){
        vecSocio[vecPrestamos[j].getIdSocio()-100]++;
    }

    for(int i=0; i<10;i++){
        cout << "El socio " << i+100 << " pidio " << vecSocio[i] << " libros" << endl;
    }
}

void Resolucion::punto4(Libro *vLibros, Prestamo *vPrestamos) {

    std::string vecLibro[10]={"Sin prestar", "Sin prestar" ,"Sin prestar" ,"Sin prestar"
    ,"Sin prestar" ,"Sin prestar"," Sin prestar" ,"Sin prestar" , "Sin prestar" ,"Sin prestar"};

    for(int j=0 ; j < 10 ;j++){
        vecLibro[vPrestamos[j].getNumLibro()-1000] = " Prestado";
    }
    for(int j=0 ; j < 10 ;j++){
        if(vecLibro[j]=="Sin prestar"){

        cout << "El libro - Titulo: " << vLibros[j].getNombre() << "\t" << vecLibro[j] << endl;
        }
    }
}

void Resolucion::punto5(Libro *vLibros, Socio *vSocios, Prestamo *vPrestamos) {

    cout << "--- PRESTAMOS NO DEVUELTOS ---" << endl << endl;

    Fecha fechaCero;
    std::string nombreLibro;
    std::string nombreSocio;

    for (int i = 0; i < 10; i++) {

        if (vPrestamos[i].getdevolucion().getDia() == fechaCero.getDia()) {
            nombreLibro = vLibros[vPrestamos[i].getNumLibro()-1000].getNombre();
            nombreSocio = vSocios[vPrestamos[i].getIdSocio()-100].getNombre() + " "
             + vSocios[vPrestamos[i].getIdSocio()-100].getApellido();

            cout << "Libro: " << nombreLibro << endl;
            cout << "Socio: " << nombreSocio << endl;
            cout << "Fecha de Prestamo: ";
            vPrestamos[i].getPrestamo().mostrar();
        }
    }
}

void Resolucion::punto6(Prestamo *vecPrestamos){

    std::string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo",
                                   "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
                                   "Noviembre", "Diciembre"};

    int mes;
    bool prestamoEnMes[10] = {};

    do {
        cout << "Ingrese el mes a consultar (1-12): ";
        cin >> mes;
    } while (mes < 1 || mes > 12);

    for (int i = 0; i < 10; i++) {
        if (vecPrestamos[i].getPrestamo().getMes() == mes) {
            prestamoEnMes[vecPrestamos[i].getIdSocio() - 100] = true;
        }
    }

    bool todosConPrestamo = true;

    for (int i = 0; i < 10; i++) {
        if (!prestamoEnMes[i]) {
            cout << "El socio " << i + 100 << " no tuvo prestamos en " << meses[mes-1] << endl;
            todosConPrestamo = false;
        }
    }

    if (todosConPrestamo) {
        cout << "Todos los socios tuvieron prestamos en " << meses[mes-1] << endl;
    }
}

void Resolucion::punto7(Prestamo *vecPrestamo, Libro *vecLibro, Socio *vecSocio){

    int matriz[10][10]={0};

    int idSocio;
    int idLibro;

    for(int i=0; i < 10; i++){

        idSocio = vecPrestamo[i].getIdSocio() - 100;
        idLibro = vecLibro[i].getIsbn() - 1000;

        matriz[idSocio][idLibro]++;
    }

    cout << "cantidad de libros pedidos por socio: " << endl;

    Socio vecAuxSocio[10];
    int pos;
    for(int s=0; s < 10; s++){
        pos = vecSocio[s].getIdSocio()-100;
        vecAuxSocio[pos] = vecSocio[s];
    }

    for(int s=0; s < 10; s++){
        cout << endl << "SOCIO: " << vecAuxSocio[s].getIdSocio() << " " << vecAuxSocio[s].getNombre() << " " << vecAuxSocio[s].getApellido() << endl;

        for(int l=0; l < 10; l++){
            cout << vecLibro[l].getNombre() << " " << matriz[s][l] << endl;
        }
    }
}

