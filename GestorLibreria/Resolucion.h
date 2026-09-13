#pragma once
#include "socio.h"
#include "prestamo.h"
#include "libro.h"
#include <iostream>

class Resolucion{

public:
    void punto3(Prestamo *vecPrestamos);
    void punto4(Libro *vLibros, Prestamo *vPrestamos);
    void punto5(Libro *vLibros, Socio *vSocios, Prestamo *vPrestamos);
    void punto6(Prestamo *vecPrestamos);
    void punto7(Prestamo *vecPrestamo, Libro *vecLibro, Socio *vecSocio);

private:

};
