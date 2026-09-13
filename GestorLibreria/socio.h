#pragma once
#include "fecha.h"
#include "persona.h"

using namespace std;

class Socio: public Persona{

private:
    int _idSocio;
public:

    void setIdSocio(int id);
    int getIdSocio();

    void cargar();
    void mostrar();
};

