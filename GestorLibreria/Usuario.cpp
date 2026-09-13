#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(std::string nombre, std::string clave, std::string rol)
{
    _nombre = nombre;
    _clave = clave;
    _rol = rol;
}

std::string Usuario::getName()
{
    return _nombre;
}

std::string Usuario::getPassword()
{
    return _clave;
}

std::string Usuario::getRol()
{
    return _rol;
}

void Usuario::setName(std::string nombre)
{
	_nombre = nombre;
}

void Usuario::setPassword(std::string clave)
{
	_clave = clave;
}

void Usuario::setRol(std::string rol)
{
    _rol = rol;
}

int Usuario::buscarUsuario(Usuario usuarios[], int cantidad, string nombre, string clave)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (usuarios[i].getName() == nombre &&
			usuarios[i].getPassword() == clave)
		{
			return i;
		}
	}

	return -1;
}

int Usuario::iniciarSesion(Usuario usuarios[5]) {
	int intentos = 0;
	int indice = -1;
	string nombre;
	string clave;

	while (intentos < 3 && indice == -1)
	{
		cout << "Ingrese su nombre: ";
		cin >> nombre;

		cout << "Ingrese su clave: ";
		cin >> clave;

		indice = buscarUsuario(usuarios, 5, nombre, clave);

		if (indice == -1)
		{
			intentos++;

			cout << endl << "Credenciales incorrectas." << endl;
			cout << "Intentos restantes: " << 3 - intentos << endl;
		}
	}

	return indice;
}

void Usuario::mostrarSaludo(Usuario usuario)
{
	std::cout << std::endl << " Bienvenido, " << usuario.getName() << std::endl;
	std::cout << " Has ingresado como: " << usuario.getRol() << std::endl;
}

void Usuario::inicioSesion(int nUsuario, Usuario usuarios[]) {
	if (nUsuario == -1) {
		cout << endl << "Se han agotado los 3 intentos." << endl;
		cout << "El programa finalizara." << endl;
		exit(-1); // ERROR DE CREDENCIALES
	}
	else {
		mostrarSaludo(usuarios[nUsuario]);
	}
}
