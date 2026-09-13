#include <string>
#pragma once
#include "fecha.h"

class Persona {

protected:
    int _dni;
    std::string _apellido;
    std::string _nombre;
    int _numTelefono;
    std::string _email;
    ///También quiere agregar el domicilio: calle, número, piso, departamento,
    /// localidad, código de localidad, provincia
    Fecha _fechaNacimiento;
public:
    void setDni(int dni);
    int getDni();

    void setApellido(std::string apellido);
    std::string getApellido();

    void setNumTelefono(int numTelefono);
    int getNumTelefono();

    void setNombre(std::string nombre);
    std::string getNombre();

    void setEmail(std::string email);
    std::string getEmail();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();

    void cargar();
    void mostrar();

};
