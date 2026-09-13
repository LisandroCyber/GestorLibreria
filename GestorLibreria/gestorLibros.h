#pragma once
#include "gestorLibros.h"
#include "socio.h"
#include "prestamo.h"
#include "Resolucion.h"
#include "libro.h"
#include "Menu.h"

class GestorLibros
{
private:

    Prestamo _prestamo;
    Libro _libro;
    Socio _socio;

	Menu _menuPrincipal;
	void cargarVector(Socio *vSocios, Libro *vLibros, Prestamo *vPrestamos);
	void mostrarVectores(Libro *vLibros, Prestamo *vPrestamos, Socio *vSocios);

public:

	GestorLibros();
	void mostrarMenu();

};

