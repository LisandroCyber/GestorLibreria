#include <iostream>
#include <string>
#include "persona.h"

void Persona::setDni(int dni){
    _dni = dni;
}

int Persona::getDni(){
    return _dni;
}

void Persona::setApellido(std::string apellido){
    _apellido = apellido;
}

std::string Persona::getApellido(){
    return _apellido;
}

void Persona::setNumTelefono(int numTelefono){
    _numTelefono = numTelefono;
}

int Persona::getNumTelefono(){
    return _numTelefono;
}

void Persona::setNombre(std::string nombre){
    _nombre = nombre;
}

std::string Persona::getNombre(){
    return _nombre;
}

void Persona::setEmail(std::string email){
    _email = email;
}

std::string Persona::getEmail(){
    return _email;
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento(){
    return _fechaNacimiento;
}

void Persona::cargar(){

    std::cout << "DNI: ";
    std::cin >> _dni;

    std::cout << "Apellido: ";
    std::cin >> _apellido;

    std::cout << "Nombre: ";
    std::cin >> _nombre;

    std::cout << "Numero de telefono: ";
    std::cin >> _numTelefono;

    std::cout << "Email: ";
    std::cin >> _email;

    std::cout << "Fecha de nacimiento: " << std::endl;
    _fechaNacimiento.cargar();
}

void Persona::mostrar(){

    std::cout << "DNI: " << _dni << std::endl;
    std::cout << "Apellido: " << _apellido << std::endl;
    std::cout << "Nombre: " << _nombre << std::endl;
    std::cout << "Numero de telefono: " << _numTelefono << std::endl;
    std::cout << "Email: " << _email << std::endl;
    std::cout << "Fecha de nacimiento: ";
    _fechaNacimiento.mostrar();
}
