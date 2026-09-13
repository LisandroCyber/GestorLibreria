#pragma once
#include "persona.h"

class Empleado: public Persona{
private:
    int _idEmpleado;
    Fecha _fechaIncorporacion;
    float _sueldo;
    ///También quiere agregar el domicilio: calle, número, piso, departamento, localidad, código de localidad, provincia
public:
    void setID(int id);
    int getID();

    void setFechaIncorporacion(Fecha fechaIncorporacion);
    Fecha getFechaIncorporacion();

    void setSueldo(float sueldo);
    float getSueldo();

    void cargar();
    void mostrar();
};
