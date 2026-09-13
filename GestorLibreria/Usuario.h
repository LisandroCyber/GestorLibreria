#pragma once
#include <string>
using namespace std;

class Usuario
{
	std::string _nombre;
	std::string _clave;
	std::string _rol;

	void setName(std::string newName);
	void setPassword(std::string newPassword);
	void setRol(std::string newRol);

public:
	Usuario(std::string nombre, std::string pass, std::string rol);

	std::string getName();
	std::string getPassword();
	std::string getRol();

    int buscarUsuario(Usuario usuarios[], int cantidad, string nombre, string clave);
    int iniciarSesion(Usuario usuarios[5]);
    void mostrarSaludo(Usuario usuario);
    void inicioSesion(int nUsuario, Usuario usuarios[]);

};
