#include "Menu.h"
#include "gestorLibros.h"

GestorLibros::GestorLibros()
: _menuPrincipal(8) {

	_menuPrincipal.setItem(1, "CARGAR VECTORES");
	_menuPrincipal.setItem(2, "MOSTRAR VECTORES");
	_menuPrincipal.setItem(3, "CANTIDAD DE LIBROS POR SOCIO");
	_menuPrincipal.setItem(4, "LIBROS SIN PRESTAR");
	_menuPrincipal.setItem(5, "LIBROS SIN DEVOLVER");
    _menuPrincipal.setItem(6, "SOCIOS SIN PRESTAMOS");

	_menuPrincipal.setItem(7, "CANTIDAD DE PEDIDOS POR LIBRO DE SOCIO");

	_menuPrincipal.setItem(8, "CANTIDAD DE PRESTAMOS POR MES");

}

void GestorLibros::mostrarMenu() {

	bool salir = false;

	Socio vSocios[10];
    Libro vLibros[10];
    Prestamo vPrestamos[10];
    Resolucion resolucion;

	do {
        system("cls");
		_menuPrincipal.dibujarMenu();
		int opcion = _menuPrincipal.obtenerRespuesta();
        system("cls");
		switch (opcion) {

		case 1:
                cargarVector(vSocios, vLibros, vPrestamos);
			break;

		case 2:
                mostrarVectores(vLibros, vPrestamos, vSocios);
			break;
		case 3:

                resolucion.punto3(vPrestamos);
			break;
        case 4:

                resolucion.punto4(vLibros, vPrestamos);
			break;
        case 5:

                resolucion.punto5(vLibros ,vSocios, vPrestamos);
			break;
        case 6:
                resolucion.punto6(vPrestamos);

            break;
        case 7:
                resolucion.punto7(vPrestamos, vLibros, vSocios);

			break;
        case 8:
                ///resolucion.punto8();

			break;

		case 0:
			salir = true;
			break;
		}
        system("pause");
	} while (!salir);

}


void GestorLibros::cargarVector(Socio *vSocios, Libro *vLibros, Prestamo *vPrestamos) {
	// Listas de datos reales para la carga automática
    string nombresLibros[10] = {
        "Don Quijote de la Mancha", "Cien anos de soledad", "El principito",
        "Ficciones", "Pedro Paramo", "La ciudad y los perros",
        "Rayuela", "El aleph", "La casa de los espiritus", "Crónica de una muerte anunciada"
    };

    string autoresLibros[10] = {
        "Miguel de Cervantes", "Gabriel Garcia Marquez", "Antoine de Saint-Exupery",
        "Jorge Luis Borges", "Juan Rulfo", "Mario Vargas Llosa",
        "Julio Cortazar", "Jorge Luis Borges", "Isabel Allende", "Gabriel Garcia Marquez"
    };

    string nombresSocios[10] = {
        "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Diego", "Sofia", "javier", "Elena"
    };

    string apellidosSocios[10] = {
        "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Gomez", "Perez", "Sanchez", "Fernandez", "Romero", "Diaz"
    };

    // 1. Cargar el vector de Libros con datos reales
    for (int i = 0; i < 10; i++) {
        vLibros[i].setIsbn(1000 + i); // ISBNs del 1000 al 1009
        vLibros[i].setNombre(nombresLibros[i]);
        vLibros[i].setAutor(autoresLibros[i]);
        vLibros[i].setFechaPublicacion(Fecha(1, 1, 1950 + (i * 5))); // Fechas de publicación variadas
        vLibros[i].setCantEjemplares(3 + i);
    }

    // 2. Cargar el vector de Socios con datos reales
    for (int i = 0; i < 10; i++) {
        vSocios[i].setIdSocio(100 + i); // IDs del 100 al 109
        vSocios[i].setDni(40000000 + (i * 1234)); // DNIs ficticios pero con formato real
        vSocios[i].setNombre(nombresSocios[i]);
        vSocios[i].setApellido(apellidosSocios[i]);

        // Genera emails realistas basados en sus nombres
        string emailMuestra = nombresSocios[i] + "." + apellidosSocios[i] + "@email.com";
        vSocios[i].setEmail(emailMuestra);

        vSocios[i].setNumTelefono(15400000 + i);
        vSocios[i].setFechaNacimiento(Fecha(15, 6, 1985 + i));
    }

    // 3. Cargar el vector de Prestamos respetando las relaciones (ISBN e ID existentes)
    for (int i = 0; i < 10; i++) {
        vPrestamos[i].setNumLibro(vLibros[i].getIsbn());   // Toma un ISBN válido del vector
        vPrestamos[i].setIdSocio(vSocios[i].getIdSocio());     // Toma un ID válido del vector
        vPrestamos[i].setPrestamo(Fecha(1, 9, 2026));
        vPrestamos[i].setDevolucion(Fecha(15, 9, 2026));
    }

    vPrestamos[9].setNumLibro(vLibros[0].getIsbn());
    vPrestamos[9].setDevolucion(Fecha(0, 0, 0));
}

void GestorLibros::mostrarVectores(Libro *vLibros, Prestamo *vPrestamos, Socio *vSocios){
    cout<<"LIBROS"<<endl;
    for(int i=0;i<10;i++){
        vLibros[i].mostrar();
    }

    cout<<endl;
    system("pause");
    cout<<"SOCIOS"<<endl;
    for(int i=0;i<10;i++){
        vSocios[i].mostrar();
    }
    system("pause");
    cout<<endl<<"PRESTAMOS"<<endl;
    for(int i=0;i<10;i++){
        vPrestamos[i].mostrar();
    }

    cout<<endl;
}
